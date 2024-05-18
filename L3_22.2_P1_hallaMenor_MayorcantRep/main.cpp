/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 10 de mayo de 2024, 12:11
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#define N 30
#include "funciones.h"
using namespace std;
int hallaMenor(int arregloPesos[N],int ini,int fin,int &menorPeso);

int main(int argc, char** argv) {
    int n=0; 
    int arregloPesos[N]{}; 
    int menorPeso; 
    int arrInd[N]{},cantDias=0;
    leerPesos(arregloPesos,n,"pesos.txt"); 
    
    menorPeso = hallaMenor(arregloPesos,0,n-1,menorPeso); 
    cout <<"el menor peso es: "<<menorPeso<<endl;

    cantDias = hallaMaxIntervalo(arrInd,menorPeso,arregloPesos,0,n-1);
    cout <<cantDias<<endl;
    cout <<"indices: "<<arrInd[0]<<"-"<<arrInd[1]<<endl;
    return 0;
}

int hallaMaxIntervalo(int arrInd[N],int numBus,int arreglo[N],int ini,int fin){
    if(ini==fin){
//        if(arreglo[ini]==numBus) return 1;
//        else return 0;
        return 1;
    }
    
    int med = (ini + fin)/2; 
    //solo nos movemos
    int izq = hallaMaxIntervalo(arrInd,numBus,arreglo,ini,med);
    int der = hallaMaxIntervalo(arrInd,numBus,arreglo,med+1,fin);
    //hallamos los posibles dias repetidos en TODO el arreglo (ya que puede estar en el medio)
    int consecutivosTotal = mezclar(arrInd,numBus,arreglo,ini,med,fin);
    
    return max(max(izq,der),consecutivosTotal);
}

int mezclar(int arrInd[N],int numBus,int arreglo[N],int ini,int med,int fin){
    int cantDer=0, cantIzq =0;
    
    if(arreglo[med]==numBus){
        for(int i=med;i>=ini;i--){
            if(arreglo[i]==numBus){
                cantIzq++;
            }else{
                            break;
            }
        }
        arrInd[0] = med - cantIzq-1;   //restamos 1 para excluir el centro

        for(int i=med+1;i<=fin;i++){
           if(arreglo[i]==numBus){
                cantDer++;
            }else{
                break;
            }
           // arrInd[1]=i;
        }
        arrInd[1] = (med+1)+cantDer-1; //restamos 1 para excluir el centro

        return cantDer+cantIzq+1; //sumamos 1 para añadir el centro 
    }else{
        arrInd[0]=med;
        arrInd[1]=med;
        return 0;
    }
}







///////////////////////////////////////////// PREGUNTA B //////////////////////////////////////////////////////////////////////////
int hallaMenor(int arregloPesos[N],int ini,int fin,int &menorPeso){
    int med = (ini + fin)/2; 
    if(ini==fin){
        return arregloPesos[ini]; 
    }
    
    int menorIzq = hallaMenor(arregloPesos,ini,med,menorPeso);
    int menorDer = hallaMenor(arregloPesos,med+1, fin,menorPeso); 
    
    if(menorIzq<menorDer) return menorIzq;
    else return menorDer;
}

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

void leerPesos(int arregloPesos[N],int &n,const char*filename){
    ifstream arch(filename,ios::in); 
    arch>>n; 
    for(int i=0; i<n; i++){
        arch>>arregloPesos[i]; 
    }
//    for(int i=0; i<n; i++){
//        cout<<arregloPesos[i]<<" "; 
//    }
//    cout <<endl; 
}





/////// CHAT GPT 


void encuentraRango(int arregloPesos[], int ini, int fin, int menorPeso, int &inicioRango, int &finRango) {
    if (ini > fin) return;

    int med = (ini + fin) / 2;

    // Encuentra el rango de días consecutivos con el menor peso en la primera mitad
    int inicioRangoIzq = med;
    int finRangoIzq = med;
    for (int i = med ; i >= ini; --i) {
        if (arregloPesos[i] != menorPeso) {
            break;
        }
        inicioRangoIzq = i;
    }
    for (int i = med + 1; i <= fin; ++i) {
        if (arregloPesos[i] != menorPeso) {
            break;
        }
        finRangoIzq = i;
    }

    // Fusiona los rangos encontrados
//    inicioRango = inicioRangoIzq;
//    finRango = finRangoIzq;
//    if (finRangoDer - inicioRangoDer > finRango - inicioRango) {
//        inicioRango = inicioRangoDer;
//        finRango = finRangoDer;
//    }
}

void diasMenorPeso(int arregloPesos[], int ini, int fin, int &cantidadDias, int &inicioRango, int &finRango) {
    if (ini == fin) {
        cantidadDias = 1;
        inicioRango = ini;
        finRango = fin;
        return;
    }

    int med = (ini + fin) / 2;

    // Encuentra el menor peso en la primera mitad
    int cantidadDiasIzq, inicioRangoIzq, finRangoIzq;
    diasMenorPeso(arregloPesos, ini, med, cantidadDiasIzq, inicioRangoIzq, finRangoIzq);

    // Encuentra el menor peso en la segunda mitad
    int cantidadDiasDer, inicioRangoDer, finRangoDer;
    diasMenorPeso(arregloPesos, med + 1, fin, cantidadDiasDer, inicioRangoDer, finRangoDer);

    // Encuentra el rango de días consecutivos con el menor peso en ambas mitades
    int inicioRangoTemp, finRangoTemp;
    encuentraRango(arregloPesos, ini, fin, arregloPesos[ini], inicioRangoTemp, finRangoTemp);

    // Fusiona los rangos encontrados en ambas mitades
    int cantidadDiasTemp = finRangoTemp - inicioRangoTemp + 1;
    if (cantidadDiasIzq >= cantidadDiasDer && cantidadDiasIzq >= cantidadDiasTemp) {
        cantidadDias = cantidadDiasIzq;
        inicioRango = inicioRangoIzq;
        finRango = finRangoIzq;
    } else if (cantidadDiasDer >= cantidadDiasIzq && cantidadDiasDer >= cantidadDiasTemp) {
        cantidadDias = cantidadDiasDer;
        inicioRango = inicioRangoDer;
        finRango = finRangoDer;
    } else {
        cantidadDias = cantidadDiasTemp;
        inicioRango = inicioRangoTemp;
        finRango = finRangoTemp;
    }
}
