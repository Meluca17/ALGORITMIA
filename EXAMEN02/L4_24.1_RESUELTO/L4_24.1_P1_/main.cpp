
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 7 de junio de 2024, 18:35
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"

//se le pasa por valor pq no quiero q esta estructura se modifique 
struct ArbolBinario aplicar_arbol(ArbolBinarioBusqueda arbol_paquetes,
        ArbolBinario &arbol_sistema);
void aplicarArbolRecursivo(struct NodoArbol *&nodo_paquetes,
        struct NodoArbol *nodo_sistema);
bool determinar_anomalia(ArbolBinario &arbol_resultado);
bool verificarABB(ArbolBinario &arbol);
bool verificarABBRecursivo(NodoArbol *nodo,int,int);

/*
 * 
 */
int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol_paquetes;
    ArbolBinario arbol_sistema,arb1,arb2,arb3,arb4, arbol_resultado;
    
    construir(arbol_sistema);
    construir(arbol_resultado);
    construir(arbol_paquetes);
    insertar(arbol_paquetes,5);
    insertar(arbol_paquetes,3);
    insertar(arbol_paquetes,9);
    
    plantarArbolBinario(arb1,nullptr,2,nullptr);
    plantarArbolBinario(arb2,nullptr,3,nullptr);
    plantarArbolBinario(arb3,arb1,7,arb2);
    plantarArbolBinario(arb4,nullptr,8,nullptr);
    plantarArbolBinario(arbol_sistema,arb3,1,arb4);
    
    /////////////////// PARTE B /////////////////////////
    arbol_resultado = aplicar_arbol(arbol_paquetes,arbol_sistema);
    recorrerEnOrden(arbol_resultado);
    
    /////////////////// PARTE C /////////////////////////
    if(determinar_anomalia(arbol_resultado)){
        cout<<endl<<"Sin eventos sospechosos"<<endl;
    }
    else{
        cout<<endl<<"Anomalia detectada"<<endl;
    }
    
    destruirArbolBinario(arbol_resultado);
    destruirArbolBinario(arbol_sistema);
    //destruirArbolBinario(arbol_paquetes.arbolBinario);
    return 0;
}


struct ArbolBinario aplicar_arbol(ArbolBinarioBusqueda arbol_paquetes,
        ArbolBinario &arbol_sistema){
    ArbolBinario resultado;
    
    aplicarArbolRecursivo(arbol_paquetes.arbolBinario.raiz,arbol_sistema.raiz);
    resultado.raiz  = arbol_paquetes.arbolBinario.raiz;
    
    //resultado.raiz = nullptr;
    return resultado;
}
void aplicarArbolRecursivo(struct NodoArbol *&nodo_paquetes,
        struct NodoArbol *nodo_sistema){
    if(esNodoVacio(nodo_paquetes) or esNodoVacio(nodo_sistema)) return;
    
    if(not esNodoVacio(nodo_paquetes)){
        //imprimeNodo(nodo_paquetes);
        nodo_paquetes->elemento += (numeroNodosRecursivo(nodo_sistema) 
                - numeroHojasRecursivo(nodo_sistema));
        
        aplicarArbolRecursivo(nodo_paquetes->izquierda,nodo_sistema->izquierda);
        aplicarArbolRecursivo(nodo_paquetes->derecha,nodo_sistema->derecha);
    }
}
 
bool determinar_anomalia(ArbolBinario &arbol_resultado){
    bool sumaNodospar=false;
    if(sumarNodos(arbol_resultado) %2 ==0) sumaNodospar = true;
    
    if(verificarABB(arbol_resultado) and sumaNodospar){
        return true;
    }
    else{
        return false;
    }
}

bool verificarABB(ArbolBinario &arbol){
    return verificarABBRecursivo(arbol.raiz,-999,999);
}

bool verificarABBRecursivo(NodoArbol *nodo,int min, int max){
    // Caso base: nodo es nulo
    if (esNodoVacio(nodo)) return true;

    // Verificar que el dato del nodo actual está dentro del rango permitido
    if (nodo->elemento <= min || nodo->elemento >= max) return false;

    // Verificar recursivamente los subárboles izquierdo y derecho
    return verificarABBRecursivo(nodo->izquierda, min, nodo->elemento) \
            && verificarABBRecursivo(nodo->derecha, nodo->elemento, max);
}


