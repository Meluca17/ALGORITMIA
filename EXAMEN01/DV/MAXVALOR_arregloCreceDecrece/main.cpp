/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 6 de mayo de 2024, 19:42
 */

#include <iostream>
#include <iomanip>
#define N 11
using namespace std;

int maxValor(int arreglo[N], int ini,int fin){
    if(ini>=fin) return arreglo[ini];
    int med = (fin+ini)/2; 
    if(arreglo[med]  < arreglo[med+1]){
        return maxValor(arreglo,med+1,fin); 
    }else{
        return maxValor(arreglo,ini,med); 
    }
}

int main(int argc, char** argv) {
    int arreglo[N] = {10,19,15,14,3,2};
    int n=6; 
    cout <<"El maximo valor es: "<<maxValor(arreglo,0,n-1);
    
    return 0;
}

