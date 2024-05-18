/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 10 de mayo de 2024, 20:29
 */

#include <iostream>
#include <iomanip>
#define N 10
#define P 2
using namespace std;
int maximoInterCreciente(int &diaIni, int &diaFin,int arreglo[N],int ini,int fin);
int max(int a, int b);
int mezcla(int &diaIni, int &diaFin,int arreglo[N],int ini,int med,int fin);
int buscarCentro(int arreglo[N],int inicio,int medio,int fin){
    int cuentaIzq, cuentaDer;
    if (arreglo[medio]<arreglo[medio+1]){
        /*Evaluo para la izquierda*/
        cuentaIzq = 1;
        for (int k=medio; k>=inicio; k--){
            if (arreglo[k-1]<arreglo[k]){
                cuentaIzq++;
            }
            else{
                break;
            }
        }
        /*Evaluo para la derecha*/
        cuentaDer = 1;
        for (int k=medio+1; k<=fin; k++){
            if (arreglo[k]<arreglo[k+1]){
                cuentaDer++;
            }
            else{
                break;
            }
        }
        return cuentaIzq + cuentaDer;
    }
    else{
        return 1;
    }
}



int main(int argc, char** argv) {
    int arreglo[N]={10,20,15,10,12,10,13,18};
    int n=8;
    int diaIni=0;
    int diaFin=0;
    int maxIntervalo=0;
    
    maxIntervalo = maximoInterCreciente(diaIni,diaFin,arreglo,0,n-1);
    cout<<maxIntervalo<<endl;
    diaIni++;
    diaFin++;
    cout <<"Del dia: "<<diaIni<<"  al dia "<<diaFin<<endl;
    
    return 0;
}

int maximoInterCreciente(int &diaInicial, int &diaFinal,int arreglo[N],int ini,int fin){
    if(ini==fin) return 1; //como min se considera 1 en el intervalo :)) 
    int med = (fin + ini)/2;
    
    //ME MUEVO DERECHA E IZQUIERDA
    int diaIni1,diaFin1, diaFin2,diaIni2,diaIni3,diaFin3;
    int izq = maximoInterCreciente(diaIni1,diaFin1,arreglo,ini,med);
    int der = maximoInterCreciente(diaIni2,diaFin2,arreglo,med+1,fin);
    int maxIntervaloTodos = mezcla(diaIni3,diaFin3,arreglo,ini,med,fin);
    
    if(izq>der and izq>maxIntervaloTodos){
        diaInicial=diaIni1;
        diaFinal = diaFin1;
        return izq;
  }else if(der>izq and der>maxIntervaloTodos){
      diaInicial=diaIni2;
        diaFinal = diaFin2;
        return der;
  }else{
      diaInicial=diaIni3;
        diaFinal = diaFin3;
        return maxIntervaloTodos;
  }
      
}

int mezcla(int &diaIni, int &diaFin,int arreglo[N],int ini,int med,int fin){
    int cant=0,i,k;
    if(arreglo[med]<=arreglo[med+1]){ //si se cumple se suma 1 para añadir el centro 
        cant++;
         //recorro izquierda
        //cantIzq=1;
        for(i=med;i>ini;i--){
            if(arreglo[i-1]<=arreglo[i]){  //17 18
                cant++; 
            }else break;
        }
        diaIni = i;
        
         //recorro derecha   
        for(k=med;k<=fin;k++){
            if(arreglo[k]<=arreglo[k+1]){   // 17 18
                cant++;              
            }else break;
        }
        diaFin=k;
        
        return cant;
    }else{
        return 0;
    }
}

int max(int a, int b){
    if(a>=b) return a;
    else return b;
}