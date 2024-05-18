/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: mell1
 *
 * Created on 10 de mayo de 2024, 12:15
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#define N 30
using namespace std; 

void leerPesos(int arregloPesos[N],int &n,const char*filename); 
//
int hallaMaxIntervalo(int arrInd[N],int numBus,int arreglo[N],int ini,int fin);
int mezclar(int arrInd[N],int numBus,int arreglo[N],int ini,int med,int fin);

#endif /* FUNCIONES_H */

