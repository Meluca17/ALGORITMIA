/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 6 de mayo de 2024, 16:32
 */

#include <iostream>
#include <iomanip>
#define N 11
using namespace std;

int buscaSinPareja(int arreglo[N],int ini,int fin){
    if (ini>fin){
        return -1; /*-1 indica que todos tienen su par*/
    }
    
    if(ini==fin){
        return arreglo[ini]; 
    }
    
    int med = (fin+ini)/2; 
    if(med%2==0){ //MEDIO PAR 
        if(arreglo[med]==arreglo[med+1]){
            return buscaSinPareja(arreglo,med+2,fin);
        }else{
                return buscaSinPareja(arreglo,ini, med);
        }
    }else{ //MEDIO IMPAR 
        if(arreglo[med]==arreglo[med-1]){ //descarto la mitad izquierda
            return buscaSinPareja(arreglo,med+1,fin); 
        }else{
            return buscaSinPareja(arreglo,ini,med-1);
        }
    }
}

//int buscaSinPareja(int arreglo[N], int ini, int fin) {
//    if (ini > fin) {
//        return -1; // -1 indica que todos tienen su par
//    }
//
//    if (ini == fin) {
//        return arreglo[ini];
//    }
//
//    int med = (fin + ini) / 2;
//    if (med % 2 == 0) { // MEDIO PAR
//        if (arreglo[med] != arreglo[med - 1]) {
//            return buscaSinPareja(arreglo, med, fin);
//        } else {
//            if (med >= 2) {
//                return buscaSinPareja(arreglo, ini, med - 2);
//            } else {
//                return -1; // No hay pareja para el primer elemento
//            }
//        }
//    } else { // MEDIO IMPAR
//        if (arreglo[med] == arreglo[med - 1]) { // Descarta la mitad izquierda
//            return buscaSinPareja(arreglo, med + 1, fin);
//        } else {
//            if (med >= 1) {
//                return buscaSinPareja(arreglo, ini, med - 1);
//            } else {
//                return -1; // No hay pareja para el último elemento
//            }
//        }
//    }
//}


int main(int argc, char** argv) {
    int arreglo[N] = {2,2,3,3,4,4};
    int n=6; 
    
    cout <<"El elemento que no tiene pareja es "<<buscaSinPareja(arreglo,0,n-1);
    
    return 0;
}

