/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 1 de abril de 2024, 12:15
 */

#include <cstdlib>
#include <iostream>

#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

/*
 * 
 */

void procesaCriba(struct Lista lista, int n){
    struct Nodo * recorrido, *aux;
    int elementoEliminar;
    recorrido = lista.cabeza;
    while (recorrido->elemento*recorrido->elemento<n){
        aux = recorrido->siguiente;
        while (aux!=nullptr){
            if (aux->elemento%recorrido->elemento==0){
                elementoEliminar = aux->elemento;
                aux = aux->siguiente;
                eliminaNodo(lista,elementoEliminar);
            }
            else {
                aux = aux->siguiente;
            }            
        }
        recorrido = recorrido->siguiente;
    }
    imprime(lista);
}

void invierte(struct Lista &lista){
    struct Nodo * recorrido, *anterior, *siguiente;
    recorrido = lista.cabeza;
    anterior = nullptr;
    siguiente = nullptr;
    while (recorrido!=nullptr){
        siguiente = recorrido->siguiente;
        recorrido->siguiente = anterior;
        anterior = recorrido;
        recorrido = siguiente;
    }
    lista.cabeza = anterior;
}

int main(int argc, char** argv) {
    int n;
    struct Lista lista;
    cout << "Ingrese n: ";
//    cin >> n;
    
    n=30;
    construir(lista);
    //Voy a llenar la lista de acuerdo a lo que dice el problema
    for (int i=2; i<=n; i++){
        insertarAlFinal(lista,i);
    }
    imprime(lista);
    cout << endl;
    cout << "Luego de la criba: " << endl;
    procesaCriba(lista,n);
    invierte(lista);
    imprime(lista); 
    return 0;
}
