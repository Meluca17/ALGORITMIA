
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 3 de julio de 2024, 10:14 a. m.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cfenv>
using namespace std;
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
void insertarRecursivoNew(struct NodoArbol *& raiz, int elemento,int stock);
void plantarArbolBBNew(struct NodoArbol *& raiz, 
                    struct NodoArbol * arbolIzquierdo, int elemento, int stock,
                    struct NodoArbol * arbolDerecho);
struct NodoArbol * obtieneNodoAntiguo(NodoArbol *nodo);
void despacharProductos(ArbolBinarioBusqueda &arbol,int &numPorDespachar, int &flag);
void leeArbol(NodoArbol *&raiz, const char *filename);
void fusionarArboles(ArbolBinarioBusqueda &arbol1,ArbolBinarioBusqueda &arbol2);
void fusionarConNodos(struct NodoArbol *&raizDestino,struct NodoArbol *&raizEmisor);
void imprimirArbolesPreOrden(ArbolBinarioBusqueda &arbol1, ArbolBinarioBusqueda &arbol2);
/*
 * 
 */
int main(int argc, char** argv) {
    struct NodoArbol *antiguo=nullptr;
    ArbolBinarioBusqueda arbolAlmacen, arbolEmisor;
    construir(arbolAlmacen);
    construir(arbolEmisor);
    //insertamos los lotes
    insertarRecursivoNew(arbolAlmacen.arbolBinario.raiz,20170620,20);
    insertarRecursivoNew(arbolAlmacen.arbolBinario.raiz,20170810,20);
    insertarRecursivoNew(arbolAlmacen.arbolBinario.raiz,20180211,20);
    insertarRecursivoNew(arbolAlmacen.arbolBinario.raiz,20180409,10);
    //leelos el otro arbol (datos de archivo)
    leeArbol(arbolEmisor.arbolBinario.raiz,"arbol2.txt");
    imprimirArbolesPreOrden(arbolAlmacen,arbolEmisor);
    
    //1) FUSIONAR ARBOLES
    fusionarArboles(arbolAlmacen,arbolEmisor);
    imprimirArbolesPreOrden(arbolAlmacen,arbolEmisor);
    
    //A) NODO MAS ANTIGUO EN ABB
    antiguo = obtieneNodoAntiguo(arbolAlmacen.arbolBinario.raiz);
    //imprimeNodo(antiguo);
    //B) DESPACHAR 35 PRODUCTOS
    int flag=0,numDespachar=35;
    despacharProductos(arbolAlmacen,numDespachar,flag);
    cout<<"Arbol despachado:"<<endl;
    recorrerEnPreOrdenRecursivo(arbolAlmacen.arbolBinario.raiz);
    //
    
    return 0;
}
void imprimirArbolesPreOrden(ArbolBinarioBusqueda &arbol1, ArbolBinarioBusqueda &arbol2){
    cout<<"El primer arbol en pre orden:"<<endl;
    recorrerPreOrden(arbol1.arbolBinario);
    cout<<endl;
    cout<<"El segundo arbol en pre orden:"<<endl;
    recorrerPreOrden(arbol2.arbolBinario);
    cout<<endl;
}

void fusionarArboles(ArbolBinarioBusqueda &arbol1,ArbolBinarioBusqueda &arbol2){
    if(numeroNodos(arbol1.arbolBinario)>numeroNodos(arbol2.arbolBinario)){
        while(not esArbolVacio(arbol2.arbolBinario)){
            struct NodoArbol *minNodo= minimoArbol(arbol2.arbolBinario.raiz);
            insertarRecursivoNew(arbol1.arbolBinario.raiz,minNodo->elemento,minNodo->stock);
            eliminarNodo(arbol2,minNodo->elemento);
        }
    }else{
        fusionarConNodos(arbol2.arbolBinario.raiz,arbol1.arbolBinario.raiz);
    }
}

void fusionarConNodos(struct NodoArbol *&raizDestino,struct NodoArbol *&raizEmisor){
    //recorre el arbol emisor 
    while(true){
        NodoArbol *minimo = minimoArbol(raizEmisor);
        if(minimo==nullptr) break;
        insertarRecursivoNew(raizDestino,minimo->elemento,minimo->stock);
        raizEmisor = eliminarNodoRecursivo(raizEmisor,minimo->elemento);
    }
}

void leeArbol(NodoArbol *&raiz, const char *filename){
    ifstream arch(filename,ios::in);
    int lote,stock;
    while(true){
        arch>>lote;
        if(arch.eof()) break;
        arch>>stock;
        
        insertarRecursivoNew(raiz,lote,stock);
    }
}

void despacharProductos(ArbolBinarioBusqueda &arbol,int &numPorDespachar,int &flag){
    
    while(numPorDespachar>0){
        NodoArbol *minimo = obtieneNodoAntiguo(arbol.arbolBinario.raiz);
        if(minimo->stock<numPorDespachar){
            numPorDespachar-=minimo->stock;
            eliminarNodo(arbol,minimo->elemento);
        }else{
            minimo->stock-=numPorDespachar;
            numPorDespachar=0;
        }
    }
    
//    if(nodo==nullptr) return;
//    
//    if(numPorDespachar>0){
//        if(numPorDespachar>nodo->stock){
//            numPorDespachar -=nodo->stock;
//            //elimino ese nodo 
//            nodo->stock=0;
//            
//        }else{
//            nodo->stock-=numPorDespachar;
//            numPorDespachar=0;
//            flag=1;
//        }
//    }
//    if(flag=1) return;
//    //recorro desde los menores valores y voy descontando, si me quedo en stock 0 -> elimino 
//    despacharProductos(nodo->izquierda,numPorDespachar,flag);
}

struct NodoArbol * obtieneNodoAntiguo(NodoArbol *nodo){
    //voy a recorrer el arbol binario full izquierda
    if(nodo->izquierda==nullptr){
        return nodo;
    }
    //nos movemos
    return obtieneNodoAntiguo(nodo->izquierda);
}


void plantarArbolBBNew(struct NodoArbol *& raiz, 
                    struct NodoArbol * arbolIzquierdo, int elemento, int stock,
                    struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento; //elemento es el IDENTIFICADOR DEL LOTE (aaaammdd)
    nuevoNodo->stock = stock;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    raiz = nuevoNodo;
}

void insertarRecursivoNew(struct NodoArbol *& raiz, int elemento,int stock){
    if(esNodoVacio(raiz))
        plantarArbolBBNew(raiz, nullptr, elemento,stock, nullptr);
    else
        if (raiz->elemento > elemento)
            insertarRecursivoNew(raiz->izquierda, elemento,stock);
        else
            if(raiz->elemento < elemento)
                insertarRecursivoNew(raiz->derecha, elemento,stock);
            else
                raiz->stock+=stock;
               // cout<<endl<<"El elemento "<< elemento <<" ya se encuentra en el árbol"<< endl;
}