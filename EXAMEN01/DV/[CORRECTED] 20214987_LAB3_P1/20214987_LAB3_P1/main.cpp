

/* 
 * File:   main.cpp
 * Author: MELL ALESSANDRA CARBAJAL ROMAN 20214987
 *
 * Created on 11 de mayo de 2024, 08:22 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#define N 10
using namespace std;

int sumaNegTodos(int arreglo[N],int ini,int med,int fin){
    int i, k; 
    int sumaActual ;
    
    
    int sumaIzq=999, sumaDer =9999; //inicializamos ambas sumas en 0 
    
    //recorremos desde el medio al inicio del arreglo 
    sumaActual = 0;
    for(i=med; i>=ini;i--){ // <-|med| 
        sumaActual+=arreglo[i]; 
        if(sumaActual<sumaIzq){
            sumaIzq = sumaActual; 
        }
    }
    sumaActual = 0; 
    //recorremos desde el medio al final del arreglo 
    for(k=med+1; k<=fin;k++){ // |med| ->  
        sumaActual+=arreglo[k]; 
        if(sumaActual<sumaDer){
            sumaDer = sumaActual; 
        }
    }
    
    //retornamos la suma de ambas partes 
    return sumaDer+sumaIzq; 
}

int maxSumNegContinua(int arreglo[N],int ini,int fin){
    if(ini==fin) return 1; 
    
    int med = (ini+fin)/2; 
    
    int izq=-9999, der=-9999, todos=-9999; 
    //dividimos nuestro arreglo
    izq = maxSumNegContinua(arreglo,ini,med);
    der = maxSumNegContinua(arreglo,med+1,fin);
    //la suma minima puede estar en el centro asi que usamos esta funcion para evaluar eso 
    todos = sumaNegTodos(arreglo,ini,med,fin); 
    
    //tecnicamente, lo que hace el algoritmo es HALLAR LA SUMA MINIMA (la más neg) 
    if(izq<der and izq<todos){
        return izq; 
    }else if(der<izq and der<todos){
        return der; 
    }else if(todos<izq and todos<der){ //el ultimo caso seria que "todos" contenga la menor suma posible 
        return todos;
    }
}

int main(int argc, char** argv) {
    //arreglos de prueba 
    int arreglo[N]={2, 5, -6, 2, 3, -1, -5, 6 };
    int arr2[N]={-4, 5, 6, -4, 3, -1, -5, 6}; //n=8
    int arrPrueba[N] = {2, -3, 4, -5, -7 };
    int nPrueba = 5;
    int n=8; 
    
   
    int acumulacionNeg=0; 
    acumulacionNeg = maxSumNegContinua(arreglo,0,n-1); 
    cout <<" La acumulacion negativa mas alta es:  "<<acumulacionNeg<<endl; 
    
    return 0;
}

