
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 4 de julio de 2024, 3:15 p. m.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"
#define N 100

void llenaArbol(ArbolBinario &arbolConPalabras);
void plantarArbolBinarioNew(struct NodoArbol *& Nodoraiz, struct NodoArbol * arbolIzquierdo,
        int elemento,char letra, struct NodoArbol * arbolDerecho);
struct NodoArbol * crearNuevoNodoArbolNew(struct NodoArbol * arbolIzquierdo,int elemento,char letra, 
                                struct NodoArbol * arbolDerecho);
int existePalabra(NodoArbol *nodo,char palabras[N],char auxiliar[N], int sizePalabra,int &flag);
int verificaPalabra(char auxiliar[N],int sizePalabra);
int existeLetra(char letraBus,char palabras[N],int sizePalabra,char auxiliar[N]);
void mensajeOculto(ArbolBinario &arbolConPalabras,char palabras[N][N],char auxiliar[N],int &flag, int numPalabras);
int existePalabraGPT(NodoArbol *nodo, char palabras[N], char auxiliar[N], int sizePalabra, int &flag);

/*
 * PRACTICANDO ABB Y ABB 
 */


int main(int argc, char** argv) {
    ArbolBinario arbolConPalabras;
    construir(arbolConPalabras);
    llenaArbol(arbolConPalabras);
    //recorrerEnOrden(arbolConPalabras);
    char auxiliar[N]{};
    char palabras[N][N]={
                        {"HIJO"},
                        {"FINAL"},
                        {"MUNDO"},
                        {"DEL"},
                        {"DIA"},
                        {"CICLO"},
                        };
    int numPalabras= 6,flag=0;
    
    //  B) para el juego de palabras
    mensajeOculto(arbolConPalabras,palabras,auxiliar,flag,numPalabras);
    
    return 0;
}

/*
 * funciones
 */

void mensajeOculto(ArbolBinario &arbolConPalabras,char palabras[N][N],char auxiliar[N],
        int &flag, int numPalabras){
    
    for(int i=0; i<numPalabras;i++){
        int sizePalabra=strlen(palabras[i]);
        strcpy(auxiliar,palabras[i]);
        //int existe = existePalabra(arbolConPalabras.raiz,palabras[i],auxiliar,sizePalabra, flag);
        int existe = existePalabraGPT(arbolConPalabras.raiz,palabras[i],auxiliar,sizePalabra, flag);
        if(existe){
            cout<<palabras[i]<<endl;
        }
    }
    
}

int existePalabra(NodoArbol *nodo,char palabras[N],char auxiliar[N], int sizePalabra, int &flag){
    if(flag==1) return 0;
    //resultado[0] = 'D' ; si se guarda la modificacion 
    if(nodo==nullptr) return 1 ;
    
    //verifica la letra en cada recursividadd
    if(!existeLetra(nodo->letra,palabras,sizePalabra,auxiliar)){
        //detiene la recursion
        return 0;
    }
    
    //PUNTO FINAL: al llegar a una hoja verifica la palabra
    if(nodo->izquierda==nullptr and nodo->derecha==nullptr){
        //verifica la palabra 
        if(!verificaPalabra(auxiliar,sizePalabra)){
            flag=1;
        }else return 1;
    }

    return existePalabra(nodo->izquierda,palabras,auxiliar,sizePalabra,flag) ||
            existePalabra(nodo->derecha,palabras,auxiliar,sizePalabra,flag) ;
    if(flag==1) return 0;
}

int verificaPalabra(char auxiliar[N],int sizePalabra){
    for(int i=0;i<sizePalabra;i++){
        if(auxiliar[i]!='*'){
            return 0;
        }
    }
    return 1;
}

int existeLetra(char letraBus,char palabras[N],int sizePalabra,char auxiliar[N]){
    for(int i=0;i<sizePalabra;i++){
        if(letraBus==auxiliar[i]){
            auxiliar[i] = '*'; //se encontro la letra
            return 1;
        }
    }
    return 0;
}


int existePalabraGPT(NodoArbol *nodo, char palabras[N], char auxiliar[N], int sizePalabra, int &flag) {
    if (flag == 1) return 0;
    if (nodo == nullptr) return 0;
    
    if (!existeLetra(nodo->letra, palabras, sizePalabra, auxiliar)) {
        return 0;
    }
    
    if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
        if (verificaPalabra(auxiliar, sizePalabra)) {
            flag = 1;
            return 1;
        } else {
            return 0;
        }
    }

    int leftResult = existePalabra(nodo->izquierda, palabras, auxiliar, sizePalabra, flag);
    int rightResult = existePalabra(nodo->derecha, palabras, auxiliar, sizePalabra, flag);
    
    return leftResult || rightResult;
}








void llenaArbol(ArbolBinario &arbolConPalabras){
    plantarArbolBinarioNew(arbolConPalabras.raiz,nullptr,0,'L',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->izquierda,nullptr,0,'D',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->izquierda->izquierda,nullptr,0,'E',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->izquierda->derecha,nullptr,0,'E',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->izquierda->derecha->izquierda,nullptr,0,'R',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->izquierda->derecha->derecha,nullptr,0,'G',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->izquierda->derecha->derecha->izquierda,nullptr,0,'T',nullptr);
    
    plantarArbolBinarioNew(arbolConPalabras.raiz->derecha,nullptr,0,'I',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->derecha->izquierda,nullptr,0,'C',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->derecha->izquierda->izquierda,nullptr,0,'C',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->derecha->izquierda->izquierda->izquierda,nullptr,0,'O',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->derecha->derecha,nullptr,0,'N',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->derecha->derecha->izquierda,nullptr,0,'A',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->derecha->derecha->izquierda->izquierda,nullptr,0,'F',nullptr);
    plantarArbolBinarioNew(arbolConPalabras.raiz->derecha->derecha->izquierda->derecha,nullptr,0,'T',nullptr);
}


void plantarArbolBinarioNew(struct NodoArbol *& Nodoraiz, 
        struct NodoArbol * arbolIzquierdo,int elemento,char letra, 
        struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNew(arbolIzquierdo, 
            elemento, letra,arbolDerecho);
    Nodoraiz = nuevoNodo;
}
struct NodoArbol * crearNuevoNodoArbolNew(struct NodoArbol * arbolIzquierdo, 
                               int elemento,char letra, 
                                struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->letra = letra;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}