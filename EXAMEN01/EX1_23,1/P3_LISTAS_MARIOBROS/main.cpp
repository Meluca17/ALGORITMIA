/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 16 de mayo de 2024, 22:22
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Nodo.h"
#include "Lista.h"
#include "funciones.h"
#include "funcBatalla.h"
using namespace std;

int main(int argc, char** argv) {
    int n,numGuer;        //n peleas
    struct Lista listaIni, ejercitoBowser,ejercitoPeach, ejercitoDonkey;
    construir(listaIni);
    construir(ejercitoBowser);
    construir(ejercitoPeach);
    construir(ejercitoDonkey);
    //PARTE A
    leeDatos("Ejercito.txt",listaIni,n,numGuer);
    cout<<"Lista de guerreros: ";
    imprime(listaIni);
    //cout<<listaIni.ataqueTotal;
    //PARTE B
    formarEjercito(numGuer,listaIni,ejercitoBowser,ejercitoPeach,ejercitoDonkey);
    imprimeEjercitos(ejercitoBowser,ejercitoPeach,ejercitoDonkey);
    //PARTE C y D
    simulaBatalla(n,ejercitoBowser,ejercitoPeach,ejercitoDonkey);
    
    return 0;
}

// prueba ataque
//  int num=723;
//    int ataque = num/10;
//    cout <<ataque;