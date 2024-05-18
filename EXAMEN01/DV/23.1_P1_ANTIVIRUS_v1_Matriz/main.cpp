/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 9 de mayo de 2024, 22:09
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#define N 5
#define M 6
#define MAX_VIRUS 10
using namespace std;
///////////////////////////////////// CABECERAS ///////////////////////////////////////////////////////////////
void lecturaDatos(int arrRegistro[N][M],int arrLineasInst[N][M],int &n,int &m);
void encuentraRepetidos(int numFil,int registros[N][M],int lineasInst[N][M],int coincidencias[MAX_VIRUS],int ini, int fin);
void encuentraVirusYcoincidencias(int registros[N][M],int lineasInst[N][M],int coincidencias[MAX_VIRUS],int n, int m); 
void imprimeRespuestas(int coincidesnciasXvirus[MAX_VIRUS]); 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(int argc, char** argv) {
    int matrizRegistro[N][M]{}; 
    int matrizLineasInst[N][M]{}; 
    int n,m; 
    /////////////////////// PARTE A ///////////////////////////////////
    lecturaDatos(matrizRegistro,matrizLineasInst,n,m); 
    /////////////////////// PARTE B ///////////////////////////////////
    int coincidesnciasXvirus[MAX_VIRUS]{}; 
    encuentraVirusYcoincidencias(matrizRegistro,matrizLineasInst,coincidesnciasXvirus,n,m);
    imprimeRespuestas(coincidesnciasXvirus); 
    
    return 0;
}






// n log(n) -> recorre todo el arreglo 
void encuentraRepetidos(int numFil,int registros[N][M],int lineasInst[N][M],int coincidencias[MAX_VIRUS],int ini, int fin){
    if(ini==fin){
        if(registros[numFil][ini]>0){
            int tipoVirus = registros[numFil][ini]; 
            coincidencias[tipoVirus]+=lineasInst[numFil][ini]; 
        }
        return; 
    }
    
    int med = (ini + fin)/2; 
    encuentraRepetidos(numFil,registros,lineasInst,coincidencias,ini,med); 
    encuentraRepetidos(numFil,registros,lineasInst,coincidencias,med+1,fin); 
}

void encuentraVirusYcoincidencias(int registros[N][M],int lineasInst[N][M],int coincidencias[MAX_VIRUS],int n, int m){
    //analiza cada fila de la matriz 
    for(int i=0; i<n; i++){ //n = 5
        encuentraRepetidos(i,registros,lineasInst,coincidencias,0,m-1); 
    }
    
}

void imprimeRespuestas(int coincidesnciasXvirus[MAX_VIRUS]){
    cout <<" Se han encontrado coincidencias del tipo ";
    for(int i=0; i<MAX_VIRUS; i++){
        if(coincidesnciasXvirus[i]>0){
            cout <<i<<"   "; 
        }
    }
    cout <<endl; 
    
    for(int i=0; i<MAX_VIRUS; i++){
        if(coincidesnciasXvirus[i]>0){
            cout << "Para el virus "<<i<<", se obtienen "<<coincidesnciasXvirus[i]<<" en total."<<endl; 
        }
    }
    
    for(int i=0; i<MAX_VIRUS; i++){
        if(coincidesnciasXvirus[i]>=10){
            cout << "Por lo que se considera que el archivo cuenta con código malicioso, específicamente del virus de "
                    "registro "<<i<<endl; 
        }
    }
    
}

    /////////////////////// PARTE A ///////////////////////////////////
void lecturaDatos(int matrizRegistro[N][M],int matrizLineasInst[N][M],int &n,int &m){
    ifstream arch("antivirus.txt", ios::in); 
    
    arch>>n>>m; 
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arch>>matrizRegistro[i][j]; 
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arch>>matrizLineasInst[i][j]; 
        }
    }
    //    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout <<matrizRegistro[i][j]<<" "; 
//        }
//        cout <<endl; 
//    }
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout <<matrizLineasInst[i][j]<<" "; 
//        }
//        cout <<endl; 
//    }
}
