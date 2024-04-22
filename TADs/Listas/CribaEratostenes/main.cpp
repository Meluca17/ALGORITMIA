/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

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
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;

/*
 * 
 */

void limpiaCola(struct Cola &cola){
    while (!esColaVacia(cola)){
        desencolar(cola);
    }
}

void procesaCriba(struct Lista lista, int n, struct Cola &cola){
    struct Nodo * recorrido, *aux;
    int elementoEliminar;
    recorrido = lista.cabeza;
    //while (recorrido->elemento*recorrido->elemento<n){
    while (recorrido!=nullptr){
        aux = recorrido->siguiente;
        while (aux!=nullptr){
            if (aux->elemento%recorrido->elemento==0){
                elementoEliminar = aux->elemento;
                encolar(cola,elementoEliminar);
                aux = aux->siguiente;
                eliminaNodo(lista,elementoEliminar);
            }
            else {
                aux = aux->siguiente;
            }            
        }
        cout << "Número procesado: " << recorrido->elemento << endl;
        if (!esColaVacia(cola)){
            cout << "Números tachados para el " << recorrido->elemento << ": ";        
            imprime(cola);
            limpiaCola(cola);
        }
        else {
            cout << "No tiene números tachados" << endl;                    
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
    struct Cola cola;
    cout << "Ingrese n: ";
//    cin >> n;
    
    n=15;
    construir(lista);
    construir(cola);
    //Voy a llenar la lista de acuerdo a lo que dice el problema
    for (int i=2; i<=n; i++){
        insertarAlFinal(lista,i);
    }
    imprime(lista);
    cout << endl;
    cout << "Luego de la criba: " << endl;
    procesaCriba(lista,n,cola);
    invierte(lista);
    imprime(lista); 
    return 0;
}

