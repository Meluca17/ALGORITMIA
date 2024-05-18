/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 7 de mayo de 2024, 14:28
 */

#include <iostream>
#include <iomanip>
#define N 11
using namespace std;

int maximo(int a,int b){
    if(a>b) return a;
    else return b; 
}

int maximoDe3(int a, int b, int c){
    int maxAb = maximo(a,b); 
    
    return maximo(maxAb,c); 
}

int calculaSumaMaxExtremos(int arreglo[N],int ini,int med, int fin, int arrValoresMaxSuma[N]){
    int inicioVal = med, finVal = med+1; 
    
    int sumaizq = -999; 
    int sumader = -999;
    int sumaActual = 0; 
    
    //DE MEDIO A INICIO
    for(int i=med; i>=ini; i--){
        sumaActual += arreglo[i]; 
        //sumaizq = maximo(sumaActual,sumaizq);  //guarda la mayor suma 
        if(sumaActual>sumaizq){
            sumaizq = sumaActual; //guarda la mayor suma (lo mismo que maximo)
            inicioVal = i; 
        }   
    }
    
    sumaActual = 0; 
    for(int i=med+1; i<=fin; i++){
        sumaActual +=arreglo[i]; 
        //sumader = maximo(sumaActual,sumader); 
        if(sumaActual>sumader){
            sumader = sumaActual; 
            finVal = i; 
        }   
    }
    
    //GUARDAMOS LOS VALORES QUE HACEN QUE LA SUMA SEA MAXIMA 
    int cont=0;
    for(int i=inicioVal; i<=finVal; i++){
        arrValoresMaxSuma[cont] = arreglo[i];
        cont++; 
    }
    
    return sumader+sumaizq;
}

int sumaMax(int arreglo[N],int ini,int fin, int arrValoresMaxSuma[N]){
    if(ini==fin){
        return arreglo[ini]; 
    }
    int med = (ini+fin)/2; 
 
    int sumaIzquierda = sumaMax(arreglo,ini,med,arrValoresMaxSuma);    
    int sumaDerecha = sumaMax(arreglo,med+1,fin,arrValoresMaxSuma);
    //int sumaCentro = 0; 
    int sumaCentro = calculaSumaMaxExtremos(arreglo,ini,med,fin,arrValoresMaxSuma); 
    
    return maximoDe3(sumaIzquierda,sumaDerecha,sumaCentro); 
}

int main(int argc, char** argv) {
    int arreglo[N] = {-2,-5,6,-2,-3,1,5,-6};
    int n=8;
    int arrValoresMaxSuma[N]{}; 
    
    
    cout <<"La maxima suma entre numeros contiguos (consecutivos) es: "<<sumaMax(arreglo,0,n-1,arrValoresMaxSuma); 
    cout << endl <<"Los elementos  que suman el maximo son: "; 
    for(int i=0; i<N;i++){
        if(arrValoresMaxSuma[i]!=0){
            cout <<arrValoresMaxSuma[i]<<"  ";
        }
    }
    
    return 0;
}

