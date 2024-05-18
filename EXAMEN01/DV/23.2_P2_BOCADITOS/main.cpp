/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 7 de mayo de 2024, 16:27
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#define N 11
#define P 5
using namespace std;


void LeerDatos(char bocaditos[N][N],int &canFilas){
    ifstream arch("Datos.txt",ios::in); 
    
    arch>>canFilas;
    for(int i=0; i<canFilas;i++){
        for(int k=0;k<N;k++){ //11 bocaditos max -> arreglo (fila) 
            arch>>bocaditos[i][k];
        }
    }
//    for(int i=0; i<canFilas;i++){
//        for(int k=0;k<N;k++){ //11 bocaditos max -> arreglo (fila) 
//            cout<<bocaditos[i][k]<<" ";
//        }
//        cout <<endl;
//    }
}

//p = 5
void LeerDatosPrecios(int precios[N][P],int cantFilas){
    ifstream arch("DatosPrecios.txt",ios::in); 
    
    for(int i=0; i<cantFilas;i++){
        for(int k=0;k<P;k++){ //11 bocaditos max -> arreglo (fila) 
            arch>>precios[i][k];
        }
    }
//        for(int i=0; i<cantFilas;i++){
//        for(int k=0;k<P;k++){ //11 bocaditos max -> arreglo (fila) 
//            cout<<precios[i][k]<<" ";
//        }
//        cout <<endl;
//    }
}

void imprimeTripleBocadito(int numFil,char bocaditos[N][N],int ini,int fin){
    //CASOs BASE
//    if(ini>=fin){
//        if(bocaditos[numFil][ini]=='0') return;
//    }
    
    if(ini+2==fin){
        if(bocaditos[numFil][ini]==bocaditos[numFil][fin]){ //triplete
            cout <<"La fila "<<numFil+1<<" tiene un "<<bocaditos[numFil][ini]<<" adicional. "<<endl;
            return;
        }
        if(bocaditos[numFil][ini]=='0' or bocaditos[numFil][fin]=='0') return; //caso triplete pero con vacio
    }
    
    int med = (ini+fin)/2; 
    if(med %2 ==0){ // ES PAR
        if(bocaditos[numFil][med]==bocaditos[numFil][med+1]){   //descara izq
            imprimeTripleBocadito(numFil,bocaditos,med,fin); //se queda con med por si ahi esta el error 
        }else{
            imprimeTripleBocadito(numFil,bocaditos,ini,med);
        }
    }else{  // ES IMPAR
        if(bocaditos[numFil][med]!=bocaditos[numFil][med+1]){   //todo  izq ta bien -> lo desc
            imprimeTripleBocadito(numFil,bocaditos,med+1,fin);
        }else{
            imprimeTripleBocadito(numFil,bocaditos,ini,med+1);
        }
    }
}




void imprimePrecioMax(int numFil,int precios[N][P],int ini,int fin){
    int med = (ini+fin)/2; 
    if(precios[numFil][med] > precios[numFil][med-1] and precios[numFil][med]>precios[numFil][med+1]){
        cout << "En la fila "<<numFil+1<<", el pasajero "<<med+1<<" tiene el bocadito mas caro S/."<<precios[numFil][med]<<endl;
        return;
    }
        
    if(precios[numFil][med] < precios[numFil][med-1]){
        imprimePrecioMax(numFil,precios,ini,med);
    }else{
        imprimePrecioMax(numFil,precios,med,fin);
    }
}

//devolviendo un int
int maxValor(int numFil,int arreglo[N][P], int ini,int fin, int &ind){
    int med = (fin+ini)/2; 
    if(arreglo[numFil][med] > arreglo[numFil][med-1] and arreglo[numFil][med]>arreglo[numFil][med+1]){
        ind = med;
        return arreglo[numFil][med];
    }    
    
    if(arreglo[numFil][med]  < arreglo[numFil][med-1]){
        return maxValor(numFil,arreglo,ini,med,ind); 
    }else{
        return maxValor(numFil,arreglo,med,fin,ind); 
    }
}

int main(int argc, char** argv) {
    char bocaditos[N][N];   //n =11
    int cantFilas=0;
    int precios[N][P];
    //
    LeerDatos(bocaditos,cantFilas);
    //imprime sobrante por cada FILA
    for(int i=0; i<cantFilas;i++){
        imprimeTripleBocadito(i,bocaditos,0,N-1);
    }
     cout<<endl;
    
     // PARTE B
    LeerDatosPrecios(precios,cantFilas);
    int ind;
    for(int i=0; i<cantFilas;i++){
         ind=0;
        //imprimePrecioMax(i,precios,0,P-1);
        cout <<maxValor(i,precios,0,P-1,ind);
        cout << " asiento: "<<ind+1;
        cout <<endl;
    }
    
    
        
    return 0;
}

