
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 5 de julio de 2024, 1:33 p. m.
 */

#include <iostream>
#include <limits.h> //para la constante máxima de enteros INT_MAX
#define V 5 //cantidad de vértices del grafo
using namespace std;
void dijkstraCaminosCortos(int grafo[V][V], int origen,int distancias[V], int predecesores[V]);
int getMinimaDist(int distancias[V], bool visitado[V]);
void MostrarSolucion(int distancias[V],int predecesores[V], int origen);

void dijkstraDistanciasLargas(int grafo[V][V], int origen, int distancias[V], int predecesores[V]);
int getMaximaDist(int distancias[V], bool visitados[V]);
void MostrarSolucionL(int distancias[V], int predecesores[V], int origen);
void MostrarSolucionDestino(int distancias[V], int predecesores[V], int origen, int destino) {
    char ciudades[] = {'A', 'B', 'C', 'D', 'E'};
    if (distancias[destino] == INT_MAX) {
        cout << "No hay camino desde " << ciudades[origen] << " hasta " << ciudades[destino] << endl;
        return;
    }
    cout << "Distancia más corta desde " << ciudades[origen] << " hasta " << ciudades[destino] << ": " << distancias[destino] << endl;
    cout << "Camino: ";
    
    int v = destino;
    while (v != -1) {
        cout << ciudades[v];
        v = predecesores[v];
        if (v != -1) cout << " <- ";
    }
    cout << endl;
}

int main (){
    int distancias[V]{}; //guarda distancias mas cortas para llegar al vertice (i) desde origen
    int predecesores[V]{};
    int grafo[V][V]={{0,3,0,7,0},//Representación del Grafo: Matriz de Adyacencia
                     {3,0,4,2,0},
                     {0,4,0,5,6},
                     {7,2,5,0,4},
                     {0,0,6,4,0}};
			
	dijkstraCaminosCortos(grafo, 0,distancias,predecesores);//el vértice inicial será (a) o la posición 0.
        MostrarSolucion(distancias,predecesores,0); //mostramos el arreglo que tiene las distancias a todos los nodos
        cout<<"Solucion en especifico"<<endl;
        MostrarSolucionDestino(distancias,predecesores,0,3);
        
        dijkstraDistanciasLargas(grafo,0,distancias,predecesores);
        MostrarSolucionL(distancias,predecesores,0);
	return 0;
}

void dijkstraCaminosCortos(int grafo[V][V], int origen,int distancias[V], int predecesores[V]){
    bool visitados[V]; // aca marcamos los veritices que ya han sido visitados
    
    //1. INICIALIZA ARREGLOS Y ARREGLO EN ORIGEN
    for(int i=0; i<V;i++){
        distancias[i] = INT_MAX; // quiero el camino mas corto
        visitados[i] = false;
        predecesores[i] = -1;
    }
    distancias[origen] = 0; //distancia al origen es 0
    
    //2. PROCESA TODOS LOS VERTICES MENOS EL ORIGEN
    for(int i=0;i<V-1;i++){
        int vertMinDis= getMinimaDist(distancias,visitados);
        if(vertMinDis==-1) break;
        visitados[vertMinDis] = true; // se va a procesar ahora
        
        //creamos una copia de los vecinos de vertMinDis
        int vecinos[V]{};
        for(int i=0;i<V;i++)vecinos[i]= grafo[vertMinDis][i];
        // procesamos los vecinos que existan y no hayan sido visitados
        for(int vec=0;vec<V;vec++){
            if(!visitados[vec]and vecinos[vec]!=0 /*exista*/){
                int disNueva = distancias[vertMinDis] + vecinos[vec];
                if(disNueva < distancias[vec]){ //hay nueva distancia
                    distancias[vec] = disNueva;
                    predecesores[vec] = vertMinDis;
                }
            }
        }
        
    }
}

//función que encuentra el vértice con la distancia mínima que aún no ha sido visitado
int getMinimaDist(int distancias[V],bool visitados[V]){
    int indMin=-1, minDis=INT_MAX;
    
    for(int i=0;i<V;i++){
        //CLAVE: es un nodo que aún no ha sido visitado
        if(visitados[i]==false and distancias[i]<=minDis){
            minDis = distancias[i];
            indMin=i;
        }
    }
    return indMin;
}

void MostrarSolucion(int distancias[V], int predecesores[V], int origen) {
    char ciudades[] = {'A', 'B', 'C', 'D', 'E'};
    
    cout << "Distancias más cortas desde ciudad " << ciudades[origen] << ": " << endl;
    for (int i = 0; i < V; i++) {
        cout << "Hacia " << ciudades[i] << ": " << distancias[i] << "  Camino: ";

        int v = i;
        while (v != -1) {
            cout << ciudades[v];
            v = predecesores[v];
            if (v != -1) cout << " <- ";
        }
        cout << endl;
    }
}

void dijkstraDistanciasLargas(int grafo[V][V], int origen, int distancias[V], int predecesores[V]) {
    bool visitados[V]; // marcamos los vértices que ya han sido visitados
    
    // 1. INICIALIZA ARREGLOS Y ARREGLO EN ORIGEN
    for (int i = 0; i < V; i++) {
        distancias[i] = INT_MIN; // quiero el camino más largo
        visitados[i] = false;
        predecesores[i] = -1; // no tiene predecesor al inicio
    }
    distancias[origen] = 0; // distancia al origen es 0
    
    // 2. PROCESA TODOS LOS VÉRTICES MENOS EL ORIGEN
    for (int i = 0; i < V - 1; i++) {
        int vertMaxDis = getMaximaDist(distancias, visitados);
        if (vertMaxDis == -1) break;
        visitados[vertMaxDis] = true; // se va a procesar ahora
        
        // procesamos los vecinos que existan y no hayan sido visitados
        for (int vec = 0; vec < V; vec++) {
            if (!visitados[vec] && grafo[vertMaxDis][vec] != 0 /* exista */) {
                int disNueva = distancias[vertMaxDis] + grafo[vertMaxDis][vec];
                if (disNueva > distancias[vec]) { // hay nueva distancia mayor
                    distancias[vec] = disNueva;
                    predecesores[vec] = vertMaxDis; // actualizamos el predecesor
                }
            }
        }
    }
}

// función que encuentra el vértice con la distancia máxima que aún no ha sido visitado
int getMaximaDist(int distancias[V], bool visitados[V]) {
    int indMax = -1, maxDis = INT_MIN;
    
    for (int i = 0; i < V; i++) {
        // CLAVE: es un nodo que aún no ha sido visitado
        if (!visitados[i] && distancias[i] >= maxDis) {
            maxDis = distancias[i];
            indMax = i;
        }
    }
    return indMax;
}

void MostrarSolucionL(int distancias[V], int predecesores[V], int origen) {
    cout << "Distancias más largas desde ciudad " << origen << ": " << endl;
    for (int i = 0; i < V; i++) {
        cout << "Hacia " << i << ": " << distancias[i] << "  Camino: ";
        // Reconstruimos el camino desde el origen hasta el vértice i
        int v = i;
        while (v != -1) {
            cout << v;
            v = predecesores[v];
            if (v != -1) cout << " <- ";
        }
        cout << endl;
    }
}