
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
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"

#define N 100
void leeYcreaArbol(const char *filename,ArbolBinarioBusqueda &arbol, 
        int &tamanho); 
void insertarRecursivoNew(struct NodoArbol *& raiz, int elemento, char letra); 
void plantarArbolBBNew(struct NodoArbol *& arbol, 
                    struct NodoArbol * arbolIzquierdo, int elemento, 
                    char letra, struct NodoArbol * arbolDerecho); 
void jugarBalword(ArbolBinarioBusqueda &arbol,int tamPalabra,int numIntentos,
        char palabras[N][N],char resultado[N]);
void roundJuego(ArbolBinarioBusqueda &arbol,int tamPalabra,char palabras[N],
        char resultado[N]); 
void analizaLetra(struct NodoArbol * nodo, char &letra, int&flag, int&coinsidePos,
                    int i);
void imprimeResultado(char resultado[N],int tamPalabra,char palabra[N]);
/*
 * PRACTICANDO ABB Y ABB 
 */
int main(int argc, char** argv) {
    int tamPalabra; 
    ArbolBinarioBusqueda arbol;
    construir(arbol); 
    leeYcreaArbol("palabra.txt",arbol,tamPalabra); 
    char resultado[N]{};
    char palabras[N][N] = {
                           {'A','D','O','R','A'},
                           {'T','E','O','R','I','A'},
                           {'O','M','I','T','E'},
                           {'S','E','R','I','O'},
                           {'T','E','D','I','O'},
                           {'C','E','S','I','O'},
    };
    //recorrerEnOrden(arbol.arbolBinario); 
    jugarBalword(arbol,tamPalabra,tamPalabra,palabras,resultado);
    //roundJuego(arbol,tamPalabra,palabras[2],resultado); 
    //cout<<resultado;
    return 0;
}
/*
 * funciones 
 */
void imprimeResultado(char resultado[N],int tamPalabra,char palabra[N]){
    for(int i=0;i<tamPalabra;i++){
        if(resultado[i]!='X')cout<<resultado[i]<<" ";
        else cout<<palabra[i]<<"(x)";
    }
    cout<<endl;
}

void jugarBalword(ArbolBinarioBusqueda &arbol,int tamPalabra,int numIntentos,
        char palabras[N][N],char resultado[N]){
    bool seHalloPalabra= false; 
    int i=0,size=0,intentos=0; 
    
    while(true){
        if(intentos==numIntentos)break; 
        
        size = strlen(palabras[i]); 
        if(size!=tamPalabra){
            cout<<"Intento "<<intentos+1<<": "<<palabras[i]<<endl;
            cout<<"La longitud de la palabra ingresada no es la correcta."<<endl;
            cout<<"Vuelva a intentarlo."<<endl;
            i++; 
        }
        else{
            cout<<"Intento "<<intentos+1<<": "<<palabras[i]<<endl;
            roundJuego(arbol,tamPalabra,palabras[i],resultado); 
            imprimeResultado(resultado,tamPalabra,palabras[i]);
            //cout<<palabras[i]<<endl;
             for(int i=0;i<tamPalabra;i++) resultado[i]='0';
            intentos++;
            i++; 
        }
    }
    if(seHalloPalabra==false){
        cout <<"Lo siento, se agotaron los intentos"<<endl; 
    }
}


void roundJuego(ArbolBinarioBusqueda &arbol, int tamPalabra, char palabras[N], 
        char resultado[N]){
    for(int i = 0; i < tamPalabra; i++){
        int flag = 0; 
        int coincidePos=0; 
        char letra = palabras[i];
        analizaLetra(arbol.arbolBinario.raiz, letra, flag,coincidePos,i+1);
        if(flag==1){
            if(coincidePos==1)resultado[i] = letra;
            else resultado[i]= 'X'; 
        }else{
            resultado[i] = '_'; 
        }
    }
}

void analizaLetra(NodoArbol *nodo, char &letra, int &flag,int &coinsidePos,int i){
    
    if(!esNodoVacio(nodo)){
        analizaLetra(nodo->izquierda, letra, flag,coinsidePos,i);
        if(flag == 1) return; // Si ya se encontró la letra, salir
        // Analiza el nodo 
        if(nodo->letra == letra){
            flag = 1;
            if(nodo->elemento==i) coinsidePos=1; 
        }
        analizaLetra(nodo->derecha, letra, flag,coinsidePos,i);
        if(flag == 1) return; 
    }
}

void leeYcreaArbol(const char *filename,ArbolBinarioBusqueda &arbol, 
        int &tamanho){
    ifstream arch(filename,ios::in); 
    
    int num; 
    char letra; 
    arch>>tamanho; 
    for(int i=0; i<tamanho;i++){
        arch>>num>>letra; 
        insertarRecursivoNew(arbol.arbolBinario.raiz,num,letra); 
    }
}
void plantarArbolBBNew(struct NodoArbol *& arbol, 
                    struct NodoArbol * arbolIzquierdo, int elemento, 
                    char letra, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->letra = letra; 
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    arbol = nuevoNodo;
}

void insertarRecursivoNew(struct NodoArbol *& raiz, int elemento, char letra){
    if(esNodoVacio(raiz))
        plantarArbolBBNew(raiz, nullptr, elemento,letra, nullptr);
    else
        if (raiz->elemento > elemento)
            insertarRecursivoNew(raiz->izquierda, elemento,letra);
        else
            if(raiz->elemento < elemento)
                insertarRecursivoNew(raiz->derecha, elemento,letra);
            else
                cout<<endl<<"El elemento "<< elemento <<" ya se encuentra en el árbol"<< endl;
}
