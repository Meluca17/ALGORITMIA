/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 6 de mayo de 2024, 18:27
 */

#include <iostream>
#include <iomanip>
#define N 11
using namespace std;

int cuentaUnos(int arreglo[N], int ini, int fin, int cont){
    if(ini>fin) return cont; 
    int med = (fin+ini)/2; 
    if(arreglo[med]==1){
        return cuentaUnos(arreglo,med+1,fin,cont+(med-ini+1)); 
    }else{
        return cuentaUnos(arreglo,ini,med-1,cont); 
    }
}

int cuentaCerosCueva(int arreglo[N],int ini,int fin,int cont){
//    if(ini ==fin){
//        if(arreglo[ini]==0) cont++;
//        return cont; 
//    }
    if(ini>fin) return cont; 
    
    int med = (fin+ini)/2; 
    if(arreglo[med]==1){
        return cuentaCerosCueva(arreglo,med+1,fin,cont); 
    }else{
        return cuentaCerosCueva(arreglo,ini,med-1,cont+(fin-med+1)); 
    }
}

int main(int argc, char** argv) {
    int arreglo[N] = {1,1,0,0,0,0,0};
    int n= 7; 
    
    cout <<"El numero de 0s es: "<<cuentaCerosCueva(arreglo,0,n-1,0); 
    cout <<endl<<"El numero de 1s es: "<<cuentaUnos(arreglo,0,n-1,0); 
    return 0;
}

