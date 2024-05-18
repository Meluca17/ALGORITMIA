/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 7 de mayo de 2024, 19:25
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#define N 10            //cant max de empresas 
using namespace std;

void maxProdEmpRecursivo(int maxProdEmpresa[N],int i,int empresas[N][N],int cantEmp);
void maxProduccionEmpresas(int maxProdEmpresa[N],int empresas[N][N],int cantEmp);
void leerProduccion(int empresas[N][N], int &cantEmp){
    ifstream arch("Datos.txt",ios::in); 
    for(int i=0;i<N;i++){   // N: cant max de empresas
        for(int k=0;k<10;k++){  //10 es el intervalo de horas (intervalo dentro del arreglo) 
            arch>>empresas[i][k];
        }
        if(arch.eof()) return;
        cantEmp++;
    }
}
int MaxValorDesordenado(int numFil, int empresas[N][N],int ini, int fin);
int hallaCantRep(int i,int empresas[N][N],int numBus,int ini,int fin);
void hallaCantRep(int i, int empresas[N][N], int numBus, int ini, int fin, int& cantRep) ;
void eligeEmpresa(int indEmp,int empresas[N][N],int arrMaxValores[N],int cantEmp,int &empComprar, int &menorCantHoras);
void eligeEmpresaRecursivo(int empresas[N][N], int i_emp, int cantEmp, int *maxProdEmpresa, int &empComprar, int &menCantHoras);

int main(int argc, char** argv) {
    int empresas[N][N]; 
    int cantEmp=0; 
    leerProduccion(empresas,cantEmp);
    
//    for(int fil=0; fil<cantEmp; fil++){
//        for (int col = 0; col < N; col++){
//            cout <<empresas[fil][col]<<" "; 
//        }
//        cout <<endl; 
//    }
//    cout<<cantEmp;
    {}
    //////////////////////////////////////////////// PARTE B /////////////////////////////////////////////////////////////////////
    
    int arrMaxValores[N]{}; //
    //maxProduccionEmpresas(arrMaxValores,empresas,cantEmp);
    maxProdEmpRecursivo(arrMaxValores,0,empresas,cantEmp);
    //for(int i =0;i<cantEmp;i++) cout<<arrMaxValores[i]<< " ";
    
    //////////////////////////////////////////////// PARTE C /////////////////////////////////////////////////////////////////////
    //cout <<hallaCantRep(0,empresas,arrMaxValores[0],0,N-1);
//        int cantRep =0;
//    hallaCantRep(0,empresas,arrMaxValores[0],0,N-1,cantRep);
//    cout <<cantRep;
    int empComprar;
    int menorCantHoras=999;
    int i_emp=0;
    eligeEmpresaRecursivo(empresas,i_emp,cantEmp,arrMaxValores,empComprar,menorCantHoras);
    cout <<"Se elige a la empresa "<<empComprar <<" con horas de produccion "<<menorCantHoras<< " h."<<endl;
    
    return 0;
}

 //////////////////////////////////////////////// PARTE C /////////////////////////////////////////////////////////////////////
void eligeEmpresaRecursivo(int empresas[N][N], int i_emp, int cantEmp, int *arrMaxValores, int &empComprar, int &menCantHoras){
    if(i_emp==cantEmp) return;
    
    int cantHoras = hallaCantRep(i_emp,empresas,arrMaxValores[i_emp],0,N-1);
    cout<<"La empresa "<<i_emp+1<<" tiene "<<cantHoras<<" horas."<<endl;
    if(cantHoras<menCantHoras){
        menCantHoras = cantHoras;
        empComprar = i_emp+1;
    }
    
    eligeEmpresaRecursivo(empresas, i_emp+1, cantEmp, arrMaxValores, empComprar, menCantHoras);
}

void eligeEmpresa(int indEmp,int empresas[N][N],int arrMaxValores[N],int cantEmp,int &empComprar, int &menorCantHoras){
    int cantHoras;
    for(int i=0;i<cantEmp;i++){
        cantHoras=0;
        cantHoras = hallaCantRep(i,empresas,arrMaxValores[i],0,N-1);
        cout <<"La empresa "<<i+1<<" tiene "<<cantHoras<<"h de produccion"<<endl;
        if(cantHoras<menorCantHoras){
            menorCantHoras = cantHoras;
            empComprar= i;
        }
    }
    //eligeEmpresa(indEmp+1,empresas,arrMaxValores,cantEmp,empComprar, menorCantHoras)
}

int hallaCantRep(int i,int empresas[N][N],int numBus,int ini,int fin){
    
    if(ini==fin){
        if(empresas[i][ini]==numBus) return 1;
        else return 0;
    }
    int med = (fin+ini)/2;
    int cantIzq = hallaCantRep(i,empresas,numBus,ini,med);
    int cantDer = hallaCantRep(i,empresas,numBus,med+1,fin);
    
    return cantDer+cantIzq;
}
void hallaCantRep(int i, int empresas[N][N], int numBus, int ini, int fin, int& cantRep) {
    if (ini == fin) {
        if (empresas[i][ini] == numBus) {
            cantRep++;
        }
        return;
    }

    int med = (fin + ini) / 2;
    hallaCantRep(i, empresas, numBus, ini, med, cantRep);
    hallaCantRep(i, empresas, numBus, med + 1, fin, cantRep);
}






 //////////////////////////////////////////////// PARTE B /////////////////////////////////////////////////////////////////////
int MaxValorDesordenado(int numFil, int empresas[N][N],int ini, int fin){
    if(ini==fin){
        return empresas[numFil][ini];
    }
    
    int med = (fin+ini)/2;
    int maxIzq = MaxValorDesordenado(numFil,empresas,ini,med);
    int maxDer = MaxValorDesordenado(numFil,empresas,med+1,fin);
    
    //luego de que termine de hallar el maximo por cada lado 
    if(maxIzq>maxDer) return maxIzq;
    else return maxDer;
    
}
void maxProduccionEmpresas(int arrMaxValores[N],int empresas[N][N],int cantEmp){
    for(int i=0;i<cantEmp;i++){
        arrMaxValores[i]=MaxValorDesordenado(i,empresas,0,N-1);
    }
}

void maxProdEmpRecursivo(int arrMaxValores[N],int i,int empresas[N][N],int cantEmp){
    if(i>=cantEmp)return;
    arrMaxValores[i]=MaxValorDesordenado(i,empresas,0,N-1);
    maxProdEmpRecursivo(arrMaxValores,i+1,empresas,cantEmp);
}



//PARTE C
//numero de horas de cada empresa -> y me quedo con la menor 
//ni cuantas horas, ni donde a donde 

//n * m *