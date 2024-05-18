/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 14 de mayo de 2024, 12:05
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Nodo.h"
#include "Lista.h"
#include "funciones.h"
#include "preg1.h"
using namespace std;
#define MAX_CAM 9 



int main(int argc, char** argv) {
    //BUS: -> una lista 
    //CAMIONES: -> arr de lista 
    struct Lista arrLista[MAX_CAM]; 
    int cantCamiones, capLeo, capRa, capDon, capMig; 
    
    lecturaDatos(cantCamiones,capLeo,capRa,capDon,capMig, 
            arrLista);
//    for(int i=0; i<cantCamiones; i++){
//        imprime(arrLista[i]); 
//    }
    {}    
    ////////////////// PREGUNTA B ////////////////////////
    int cromo[cantCamiones]{}, pesobus,cargaPLeo,cargaPRa, cargaPDona,cargaPMig,
            cromoSolu[cantCamiones]{}; 
    int base = 4; //4 tortuninjas (TODAS DEBEN CARGAR UN CAMION)
    int combinaciones = pow(base,cantCamiones); 
    bool existeSolu; 
    
    for(int i=0; i<combinaciones; i++){
        //generamos la combinacion 
        cargaBin(i,cromo,cantCamiones,base);
        if(validaMinimoTortuga(cromo,cantCamiones)){
            //imprimeCromo(cromo,cantCamiones); 
//            cargaPDona = 0; 
//            cargaPLeo = 0; 
//            cargaPMig = 0; 
//            cargaPRa = 0; 
            existeSolu = validarCapacidad(cromo,cantCamiones,arrLista,capLeo,capRa,capDon,capMig); 
            if(existeSolu){
                cout <<"Existe solucion:) "<<endl<<"Combinacion: ";
                imprimeCromo(cromo,cantCamiones); 
                guardaCromoSolu(cromo,cromoSolu,cantCamiones);
                //imprimeCromo(cromoSolu,cantCamiones); 
            }
//            for(int j=0; j<cantCamiones;j++){ 
//                //LEONARDO
//                if(cromo[j]==0){ 
//                    pesobus = obtienePesoLista(arrLista[j]);  
//                    cargaPLeo+=pesobus; 
//                    if(cargaPLeo>=capLeo){
//                        existeSolu=false; 
//                        break; 
//                    }
//                }
//                //RAFAEL
//                else if (cromo[j]==1){
//                    pesobus = obtienePesoLista(arrLista[j]); 
//                    cargaPRa+=pesobus; 
//                    if(cargaPRa>=capRa){
//                        existeSolu=false; 
//                        break; 
//                    }
//                }
//                //DONATELO
//                else if(cromo[j]==2){
//                    pesobus = obtienePesoLista(arrLista[j]);
//                    cargaPDona+=pesobus; 
//                    if(cargaPDona>=capDon){
//                        existeSolu=false; 
//                        break; 
//                    }
//                }
//                //MIGUEL ANGEL
//                else{ 
//                    pesobus = obtienePesoLista(arrLista[j]);  
//                    cargaPMig+=pesobus; 
//                    if(cargaPMig>=capMig){
//                        existeSolu=false; 
//                        break; 
//                    }
//                }
    //            cout << cargaPLeo<<endl;
    //            cout << cargaPRa<<endl;
    //            cout << cargaPDona<<endl;
    //            cout << cargaPMig<<endl;
    //            cout<<endl; 

        }
    }
    
    imprimeSolucion(cromoSolu,cantCamiones,arrLista);
    return 0;
}


bool validarCapacidad(int *cromo,int cantCamiones,struct Lista *arrLista,
        int capLeo,int capRa, int capDon,int capMig){
    //recorro el cromo
    for(int i=0; i<cantCamiones; i++){
        //int pesoTotalCamion = obtienePesoLista(arrLista[i]); 
        int capacidadTort;//EN GENERAL: 
        int pesoBus = arrLista[i].pesoTotal; 
        int indTort = cromo[i];   //1 
        //ESTO SE PODRIA PONER EN UN IF 
//        if(indTort==0){
//            capacidadTort = (indTort==0)*capLeo;  
//            capLeo-=(indTort==0)*pesoTotalBus;
//            if(capacidadTort<pesoTotalBus) return false; 
//        }else if(indTort==1){
//            capacidadTort = (indTort==1)*capRa;  
//            capRa-=(indTort==1)*pesoTotalBus;
//            if(capacidadTort<pesoTotalBus) return false; 
//        }else if(indTort==2){
//            capacidadTort = (indTort==2)*capDon;  
//            capDon-=(indTort==2)*pesoTotalBus;
//            if(capacidadTort<pesoTotalBus) return false; 
//        }else{
//            capacidadTort = (indTort==3)*capMig;  
//            capMig-=(indTort==3)*pesoTotalBus;
//            if(capacidadTort<pesoTotalBus) return false; 
//        }
        
        capacidadTort = (indTort==0)*capLeo + (indTort==1)*capRa+
        (indTort==2)*capDon + (indTort==3)*capMig;  
        
        capLeo-=(indTort==0)*pesoBus;
        capRa-=(indTort==1)*pesoBus;
        capDon-=(indTort==2)*pesoBus;
        capMig-=(indTort==3)*pesoBus;
        
        if(capacidadTort<pesoBus) return false; 
    }
    return true; 
}
    

//1. max valor en base 5 (con 5 digitos) 
//2. no hay ceros               
//3. puede haber digitos repetidos [1 1 2 3  4]
//4. SI o SI debn estar el [1 2 3 4 ] 

int obtienePesoLista(struct Lista &bus){
    int peso=0; 
    //recorremos la lista y sumamos el valor de cada nodo :) 
    struct Nodo *nodo = bus.cabeza; 
    
    while(nodo!=nullptr){
        peso += nodo->elemento; 
        nodo = nodo->siguiente; 
    }
    
    return peso; 
}


//nahoi 4 -> hanoi de 3 que utiliza una pila de pivot 
//nahoi 4 PURO -> con respecto a n-2