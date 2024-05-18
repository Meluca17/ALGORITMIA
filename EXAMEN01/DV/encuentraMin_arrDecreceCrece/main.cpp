/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 7 de mayo de 2024, 13:46
 */

#include <iostream>
#include <iomanip>
#define N 11
using namespace std;

int minValor(int arreglo[N],int ini,int fin){
    if(ini>=fin) return arreglo[ini]; 
    int med = (ini+fin)/2; 
    
    if(arreglo[med] < arreglo[med+1]){
        return minValor(arreglo,ini,med); 
    }else{
        return minValor(arreglo,med+1,fin); 
    }
}

int main(int argc, char** argv) {
    int arreglo[N] = {1,2,3,4,6,8};
    int n=6;
    
    cout <<"El minimo es: "<<minValor(arreglo,0,n-1); 
    
    return 0;
}

