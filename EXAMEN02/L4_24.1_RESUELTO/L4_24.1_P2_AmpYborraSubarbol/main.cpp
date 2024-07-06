
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 5 de junio de 2024, 18:45
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NodoArbol.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"

void recorreAmplitud(struct ArbolBinario libros,int &nivel);
void recorreAmplitud(struct ArbolBinario arbol);
void borraSubArbol(struct ArbolBinario arbol,char subarbol);
NodoArbol *obtieneRaiz(struct ArbolBinario arbol);

int main(int argc, char** argv) {
    struct Datos dato1 = {"Titulo",7};
    struct Datos dato2 = {"Capitulo1",8};
    struct Datos dato3 = {"Capitulo2",5};
    struct Datos dato4 = {"Seccion1.1",6};
    struct Datos dato5 = {"Principal",10};
    struct Datos dato6 = {"Seccion2.1",3};
    struct Datos dato7 = {"Seccion2.2",4};
    struct Datos dato8 = {"Seccion1.1.1",4};
    struct Datos dato9 = {"Seccion1.1.2",2};

    struct ArbolBinario libros, arb1,arb2,arb3,arb4,arb5,arb,arb6, arb7,arb8,arb9;
    
    plantarArbolBinario(arb1,nullptr,dato9,nullptr);
    plantarArbolBinario(arb2,nullptr,dato8,nullptr);
    plantarArbolBinario(arb5,arb2,dato4,arb1);
    plantarArbolBinario(arb6,nullptr,dato5,nullptr);
    plantarArbolBinario(arb7,arb5,dato2,arb6);
    plantarArbolBinario(arb3,nullptr,dato6,nullptr);
    plantarArbolBinario(arb4,nullptr,dato7,nullptr);
    plantarArbolBinario(arb8,arb3,dato3,arb4);
    plantarArbolBinario(libros,arb7,dato1,arb8);
    
    ////////////////////// PARTE A ////////////////////////////////////
    int nivel=-1;
    recorreAmplitud(libros);
    recorreAmplitud(libros,nivel);
    if(nivel!=-1) cout <<"Se encuentra en el nivel "<<nivel<<endl<<endl;
    
    ////////////////////// PARTE B ////////////////////////////////////
    borraSubArbol(libros,'D');
    cout<<"Arbol despues de borrar su subarbol derecho: "<<endl;
    recorreAmplitud(libros);
    
    destruirArbolBinario(libros);
    return 0;
}

void recorreAmplitud(struct ArbolBinario arbol){
    struct Cola cola;
    construir(cola);
    struct NodoArbol *desencolado;
    
    encolar(cola,arbol.raiz);
    encolar(cola,nullptr);
    while(not esColaVacia(cola)){
        desencolado = desencolar(cola);
        if(desencolado!=nullptr){
            imprimeNodo(desencolado);

            if(not esNodoVacio(desencolado->izquierda))
                encolar(cola,desencolado->izquierda);
            if(not esNodoVacio(desencolado->derecha))
                encolar(cola,desencolado->derecha);
        }
        else{
            cout<<endl;
            if(not esColaVacia(cola)){ //para q no se pierda la cond de salida del while 
                encolar(cola,nullptr);
            }
        }
    }
    destruirCola(cola);
}

void recorreAmplitud(struct ArbolBinario arbol,int &nivel){
    struct Cola cola;
    construir(cola);
    struct NodoArbol *desencolado;
    int alt=0;
    
    encolar(cola,arbol.raiz);
    encolar(cola,nullptr);
    while(not esColaVacia(cola)){        
        desencolado = desencolar(cola);
        if(desencolado!=nullptr){
            //imprimeNodo(desencolado);
            if(strcmp(desencolado->elemento.titulo,"Principal")==0){
                nivel = alt;
                cout<<"Si se encuentra el capitulo Principal "<<endl;
                return;
            }
            if(not esNodoVacio(desencolado->izquierda))
                encolar(cola,desencolado->izquierda);
            if(not esNodoVacio(desencolado->derecha))
                encolar(cola,desencolado->derecha);
        }
        else{
            //cout<<endl;
            alt++;
            if(not esColaVacia(cola)){ //para q no se pierda la cond de salida del while 
                encolar(cola,nullptr);
            }
        }
    }
    
    cout<<"No se encuentra."<<endl;
    destruirCola(cola);
}

NodoArbol *obtieneRaiz(struct ArbolBinario arbol){
    return arbol.raiz;
}
void borraSubArbol(struct ArbolBinario arbol,char subarbol){
    NodoArbol *subArbolEliminar, *raiz;
    
    raiz = obtieneRaiz(arbol);
    if(subarbol=='D')subArbolEliminar = raiz->derecha;
    if(subarbol=='I')subArbolEliminar = raiz->izquierda;
    destruirRecursivo(subArbolEliminar);
    if(subarbol=='D')raiz->derecha=nullptr;
    if(subarbol=='I')raiz->izquierda=nullptr;
    
//    if(subarbol=='D') destruirRecursivo(arbol.raiz->derecha);
//    if(subarbol=='I') destruirRecursivo(arbol.raiz->izquierda);
//    
//    if(subarbol=='D') arbol.raiz->derecha=nullptr;
//    if(subarbol=='I') arbol.raiz->izquierda=nullptr;
}