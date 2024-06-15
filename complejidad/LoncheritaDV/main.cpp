/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 29 de abril de 2024, 10:23
 */

#include <iostream>
#include <iomanip>
#define N 5
#define M 5
using namespace std;


int buscarMenorCaloria(int calorias[N][M],int i,int inicio,int fin){
    //busco izq y busco derecha pq no se donde esta el menor 
    if(inicio==fin) return calorias[i][inicio]; 
    
    int medio =(inicio+fin)/2; 
    int menorIzq = buscarMenorCaloria(calorias,i,inicio,medio); 
    int menorDer = buscarMenorCaloria(calorias,i,medio+1,fin); 
    
    if(menorIzq < menorDer) return menorIzq; 
    else return menorDer; 
}



//p = ini  , q = med+1,  se ordena en un arreglo aux ,m= cont que recorre el arrreglo aux para colocar los datos ordenadosfriend
//cond de salidas: si q>=fin , si p >= med 

void merge(int menorCalorias[N],int inicio,int medio,int fin){
    int aux[N], p,q,m; 
    //m  = inicio; //ind para ordenarlo en la posicion del arr original (en el aux) 
    
    
    for(p=inicio,q=medio+1, m=inicio; p<=medio && q<=fin;   m++){
        if(menorCalorias[p]<menorCalorias[q]){
            aux[m] = menorCalorias[p]; 
            p++;
        }else{
            aux[m] = menorCalorias[q]; 
            q++; 
        }
    } 
    //VAMOS A VERIFICAR SI QUEDAN PRODUCTOS EN ALGUNO DE LOS LADOS 
    //todo lo que quedo en p lo vamos a pasar a m 
    while(p<=medio){
        aux[m] = menorCalorias[p]; 
        m++;
        p++;
    }
    
    while(q<=fin){
        aux[m] = menorCalorias[q]; 
        m++; 
        q++; 
    }
    
    //ahora paso lo que tenia en aux al arreglo original 
    for(int i=inicio; i<=fin; i++){
        menorCalorias[i] = aux[i]; 
    }
}
void mergeSort(int menorCalorias[N],int inicio, int fin){
    if(inicio ==fin) return; //cuando se trata de un solo elemento no debo ordenar nada porque ya esta ordenado 
    
    int medio = (inicio+fin) / 2; 
    mergeSort(menorCalorias,inicio,medio);  //ORDENA IZQUIERDA 
    mergeSort(menorCalorias,medio+1,fin);  //ORDENA DERECHA 
    //cuando ya esta ordenado (el elemento unitario y el otro elemento unitario ) 
    merge(menorCalorias,inicio,medio,fin); //result der + result izq , el medio me dira cual es el lado der ord y el lado izq ord 
}

/*  OJO: PODEMOS BUSCAR POR AMBOS LADOS -> motivo: no esta ordenado */
int main(int argc, char** argv) {
    int calorias[N][M] = {{12,7,9,5,18},
                                    {3,7,2,10,20},
                                    {25,12,7,8,19},
                                    {3,7,2,10,20},
                                    {3,7,2,10,20},
    }; 
    int n=5, m=5; 
    int menorCalorias[N]; 
    
    //determinar cual es la menor caloria por cada tipo de producto 
    for(int i=0; i<n; i++){ //le pasamos el i para saber en que fila estoy
        //                                                              arr          ini  fin
        menorCalorias[i] = buscarMenorCaloria(calorias,i,0,m-1); //le pasamos el i para determinar el menor de una fila 
    }
    //imprimos los menores 
    for(int i=0; i<n; i++){
        cout <<"En bruto: "<<menorCalorias[i]<<"  "; 
    }
    
    /////////////////////// ORDENAMIENTO CON MERGE SORT ////////////////////////////////////////////////////////7
        mergeSort(menorCalorias,0,n-1); //ini fin 
        
        
        
    return 0;
}

