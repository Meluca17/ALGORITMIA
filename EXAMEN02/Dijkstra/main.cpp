/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 24 de junio de 2024, 10:59
 */

#include <cstdlib>
#include <iostream>
#define V 5
#define MAX 1000

using namespace std;

/*
 * 
 */


int recorrer(int grafo[V][V],int inicio,int fin){
    int min = MAX; /*Inicializamos con un valor maximo porque nos piden el minimo*/
    if (inicio==fin){
        return 0;
    }
    for (int i=inicio+1; i<V; i++){
        if (grafo[inicio][i]){
            int distancia = grafo[inicio][i] + recorrer(grafo,i,fin);
            if (distancia<min){
                min = distancia;
            }
        }
    }
    return min;
}

void imprimirSolucion(int distancias[V], int vertElegido){
    for (int i=0; i<V; i++){
        cout << "Ciudad " <<vertElegido<<" a "
                << i << ":  " << distancias[i] << endl;
    }
}

int buscarMinima(int distancias[V],bool visitados[V]){
    int min=MAX, idMenor;
    for (int i=0; i<V; i++){
        if (!visitados[i] && distancias[i]<min){
            min = distancias[i];
            idMenor = i;
        }
    }
    return idMenor;
}
void dijkstra(int grafo[V][V],int inicio){
    int distancias[V];
    bool visitados[V];
    
    for (int i=0; i<V; i++){
        distancias[i] = MAX;
        visitados[i] = false;
    }
    
    distancias[inicio] = 0;
    
    for (int j=0; j< V-1; j++){
        int idMenor = buscarMinima(distancias,visitados);
        visitados[idMenor] = true;
        for (int k=0; k<V; k++){
            if (!visitados[k] && grafo[idMenor][k] &&
                 distancias[idMenor]!=MAX &&
                 (distancias[idMenor] + grafo[idMenor][k])<distancias[k]){
                distancias[k] = distancias[idMenor] + grafo[idMenor][k];
                
            }
        }
    }
    imprimirSolucion(distancias,inicio);
}

int main(int argc, char** argv) {
    int grafo[V][V] = {{0,3,0,7,0},
                       {3,0,4,2,0},
                       {0,4,0,5,6},
                       {7,2,5,0,4},
                       {0,0,6,4,0}};
    cout << "Sin Dijkstra: " << recorrer(grafo,0,4) << endl;
    cout << "Con Dijkstra: " << endl;
    dijkstra(grafo,1);
    return 0;
}

