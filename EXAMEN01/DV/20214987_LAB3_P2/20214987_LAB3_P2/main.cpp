/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: MELL ALESSANDRA CARBAJAL ROMAN 20214987
 *
 * Created on 11 de mayo de 2024, 08:03 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#define N 14
using namespace std;

//esta funcion no cumple, ya que recorre todo el arreglo:c
int hallaRadiacionMax(int inicioPotencia,int arreglo[N],int ini,int fin){
    if(ini==fin) return arreglo[ini]; 
    int med = (ini+fin)/2; 
    
    int izq = hallaRadiacionMax(inicioPotencia,arreglo,ini,med);
    int der = hallaRadiacionMax(inicioPotencia,arreglo,med+1,fin);
    
    if(izq>der) return izq; 
    else return der; 
}

//USAR EL INICIO DE POTENCIA PARA DESCARTAR LA OTRA MITAD DEL ARREGLO (que son 0 o -1)
//int arreglo[N]={1,1,2,2,3,2, 2, 1, 1}; ->ese indicie seria nuestro inicio :)
//la funcion se convierte en hallar sin pareja :))) 
int hallaMaxDescartando(int arreglo[N],int ini,int fin){
    //if(ini>fin) return -1;
    
    if(ini==fin){
        return arreglo[ini]+1; 
    }
    
    int med = (ini+fin)/2; 
    
    if(med%2==0){ //ES PAR 
        if(arreglo[med] ==arreglo[med+1]){
            return hallaMaxDescartando(arreglo,med+2,fin); //med y med+1 son parejita 
        }else{
            return hallaMaxDescartando(arreglo,ini,med); 
        }
    }else{ //ES IMPAR
        if(arreglo[med] ==arreglo[med-1]){
            return hallaMaxDescartando(arreglo,med-1,fin);
        }else{
            return hallaMaxDescartando(arreglo,ini,med+1);
        }
    }
}

int hallaInicioRadiacion(int arreglo[N],int ini,int fin){
    //CASO BASE 
    if(ini==fin){
        if(arreglo>0){
            return ini; 
        }
    }
    int med = (ini+fin)/2; 
    
    if(arreglo[med]<=0){
        return hallaInicioRadiacion(arreglo,med+1,fin); 
    }else{ // 1 2 3 ...
        return hallaInicioRadiacion(arreglo,ini,med); 
    }
}

int main(int argc, char** argv) {
    int arreglo[N]={0,-1,0,-1,0,1,1,2,2,3,2, 2, 1, 1};
    int n=14; 
    int maxPotencia=0; 
    int inicioPotencia = 0; 
    
    inicioPotencia = hallaInicioRadiacion(arreglo,0,n-1);
    //para probar usando el indice inicioPotencia (5) -> el arreglo de prueba seria el sgte: 
    //en el arerglo original: inicio= 5, fin = n-1 , 
    //usamos un arreglo auxiliar para fines practicos 
    int arr2[N]={1,1,2,2,3,2, 2, 1, 1};
    int n2=9;   // n2 = n-inicioPotencia -1
    maxPotencia = hallaMaxDescartando(arr2,0,n2-1);
    cout <<"La radiacion empieza a "<<inicioPotencia<<" km. "<<endl; 
    cout <<"La maxima potencia es "<<maxPotencia<<" megatones. "<<endl; 
    
    return 0;
}

