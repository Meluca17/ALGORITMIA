
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 2 de julio de 2024, 9:48 a. m.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#define M 10
#define N 6
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"

void plantarArbolBinarioNew(struct NodoArbol *&raiz, struct NodoArbol * izquierdo,
                         int elemento,char letra, struct NodoArbol * derecho);
struct NodoArbol * crearNuevoNodoArbolNew(struct NodoArbol * izquierdo, 
                               int elemento,char letra, struct NodoArbol * derecho);
bool buscarPalabraArbol(NodoArbol* raiz,char palabra[M],int pos,char aux[M]);
bool estaLetraEnPalabra(char letra,char palabra[M]);
bool verificaPalabra(char palabra[M],char aux[M],int n);


/*
 * AB Busqueda de Palabras
 */
int main(int argc, char** argv) {
    char palabras[N][M]={{'H','I','J','O','\0'},
                        {'F','I','N','A','L','\0'},
                        {'M','U','N','D','O','\0'},
                        {'D','E','L','\0'},
                        {'D','I','A','\0'}, 
                        {'C','I','C','L','O','\0'}};
    ArbolBinario arbol;
    construir(arbol);
    //subarbol izq
    plantarArbolBinarioNew(arbol.raiz,nullptr,0,'L',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda,nullptr,0,'D',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda,nullptr,0,'E',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha,nullptr,0,'E',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->izquierda,nullptr,0,'R',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->derecha,nullptr,0,'G',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->derecha->izquierda,nullptr,0,'T',nullptr);
    //subarbol derecho
    plantarArbolBinarioNew(arbol.raiz->derecha,nullptr,0,'I',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda,nullptr,0,'C',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda,nullptr,0,'C',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda->izquierda,nullptr,0,'O',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha,nullptr,0,'N',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda,nullptr,0,'A',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda->izquierda,nullptr,0,'F',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda->derecha,nullptr,0,'T',nullptr);
    
    //recorrerEnPreOrdenRecursivo(arbol.raiz);
    
    char aux[M]{};
    cout<<buscarPalabraArbol(arbol.raiz,palabras[1],0,aux);
    
    
    return 0;
}

bool buscarPalabraArbol(NodoArbol* nodo,char palabra[M],int pos, char aux[M]){
    //1. caso base 
    if(nodo==nullptr) return true;
    
    //2. verificar si letra está en palabra
    if(!estaLetraEnPalabra(nodo->letra,palabra)){
        return false;
    }else{
        //guardo la letra en un auxiliar 
        aux[pos] = nodo->letra;
        pos++;
    }
    
    //3. Verifica la palabra al llegar a UNA HOJA 
    if(nodo->izquierda==nullptr and nodo->derecha==nullptr){
        if(!verificaPalabra(palabra,aux,pos)){ //pos = n elementos del arreglo
            return false;
        }else{
            return true;
        }
    }
    
    //4. recorre a los extremos
    return buscarPalabraArbol(nodo->izquierda,palabra,pos,aux) + 
            buscarPalabraArbol(nodo->derecha,palabra,pos,aux);
}

bool verificaPalabra(char palabra[M],char aux[M],int n){
    char auxiliar[M];
    bool hayLetra;
    int sizePalabra=0;
    //trabajamos con un arreglo auxiliar para no chancar aux
    for(int i=0; i<n;i++){
        auxiliar[i] = aux[i];
    }
    //recorre palabra para verificar letra por letra
    for(int i=0; palabra[i]!='\0';i++){ //el bucle se rompe porque llega al delimitador
        sizePalabra++;
        hayLetra = false;
        //busca esa letra en auxiliar y lo marca con ' '
        for(int k=0;k<n;k++){
            if(auxiliar[k]==palabra[i]){
                auxiliar[k] = ' ';
                hayLetra=true;
                break; //rompe el bucle del 2do for
            }
        }
        if(!hayLetra) break; //si no hay uan de las letras rompe el bucle
    }
    
    return hayLetra and (sizePalabra==n);
}

bool estaLetraEnPalabra(char letra,char palabra[M]){
    //recorre toda la palabra 
    for(int i=0; palabra[i]!='\0';i++){
        if(palabra[i]==letra){
            return true;
        }
    }
    return false;
}

struct NodoArbol * crearNuevoNodoArbolNew(struct NodoArbol * izquierdo, 
                               int elemento,char letra, struct NodoArbol * derecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->letra = letra;
    nuevoNodo->izquierda = izquierdo;
    nuevoNodo->derecha = derecho;
    return nuevoNodo;
}

void plantarArbolBinarioNew(struct NodoArbol *&raiz, struct NodoArbol * izquierdo,
                         int elemento,char letra, struct NodoArbol * derecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNew(izquierdo, elemento, letra,derecho);
    raiz = nuevoNodo;
}