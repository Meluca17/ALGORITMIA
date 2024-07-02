/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 10 de junio de 2024, 11:30
 */

#include <cstdlib>
#include <iostream>
#include "NodoArbol.h"
#include "funcionesArbolesBinarios.h"
#include "ArbolBinario.h"
#define N 10
#define M 6

using namespace std;

/*
 * 
 */

struct NodoArbol * crearNuevoNodoArbolNew(struct NodoArbol * arbolIzquierdo, 
                               int elemento, char letra, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->letra = letra;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBinarioNew(struct NodoArbol * &raiz, struct NodoArbol * arbolIzquierdo,
                         int elemento, char letra, struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNew(arbolIzquierdo, elemento, letra, arbolDerecho);
    raiz = nuevoNodo;
}

int existeLetra(char letra,char palabra[N]){
    for (int i=0; palabra[i]!='\0'; i++){
        if (letra==palabra[i]){
            return 1;
        }
    }
    return 0;
}

int verificaPalabra(char palabra[N],char aux[N],int pos){
    char aux2[N];
    int hay, size=0;
    for (int i=0; i<pos; i++){
        aux2[i] = aux[i]; 
    }
    for (int i=0; palabra[i]!='\0'; i++){
        hay = 0;
        size++;
        for (int j=0; j<pos; j++){
            if (palabra[i]==aux2[j]){
                hay = 1;
                aux2[j] = ' ';
                break;
            }
        }
        if (!hay){
            break;
        }
    }
    return hay && (size==pos);
}

int existePalabra(NodoArbol * raiz,char palabra[N],char aux[N],int pos){
    if (raiz==nullptr){
        return 0;
    }
    if (existeLetra(raiz->letra,palabra)){
        aux[pos++] = raiz->letra;
    }
    else{
        return 0;
    }
    if (raiz->derecha==nullptr && raiz->izquierda==nullptr){
        if (verificaPalabra(palabra,aux,pos)){
            return 1;
        }
        else{
            return 0;
        }
    }
    return existePalabra(raiz->izquierda,palabra,aux,pos) + existePalabra(raiz->derecha,palabra,aux,pos);
}

int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);
    plantarArbolBinarioNew(arbol.raiz,nullptr,0,'L',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda,nullptr,0,'D',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha,nullptr,0,'I',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda,nullptr,0,'E',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha,nullptr,0,'E',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->izquierda,nullptr,0,'R',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->derecha,nullptr,0,'G',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->derecha->izquierda,nullptr,0,'T',nullptr);
    
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda,nullptr,0,'C',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha,nullptr,0,'N',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda,nullptr,0,'C',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda->izquierda,nullptr,0,'O',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda,nullptr,0,'A',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda->izquierda,nullptr,0,'F',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda->derecha,nullptr,0,'T',nullptr);
    char palabra[M][N] = {{'H','I','J','O','\0'},
                          {'F','I','N','A','L','\0'},
                          {'M','U','N','D','O','\0'},
                          {'D','E','L','\0'},
                          {'D','I','A','\0'},
                          {'C','I','C','L','O','\0'}};
    char aux[N];
    int pos=0;
    for (int i=0; i<M; i++){
        if (existePalabra(arbol.raiz,palabra[i],aux,pos)){
            cout << palabra[i] << endl;
        }
    }
//    recorrerPreOrden(arbol);
    return 0;
}

