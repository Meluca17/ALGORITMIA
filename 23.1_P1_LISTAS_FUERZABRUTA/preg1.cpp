/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Nodo.h"
#include "Lista.h"
#include "funciones.h"
#include "preg1.h"
using namespace std;
#define MAX_CAM 9 

void cargaBin(int num,int *cromo,int size,int base){
    for(int i=0; i<size; i++) cromo[i] = 0; 
    
    int i=0,res; 
    while(num>0){
        res = num %base; 
        num = num / base; 
        cromo[i] = res; 
        i++;
    }
}

void lecturaDatos(int &numcam,int &capLeo,int &capRa,int &capDon,
        int &capMig, struct Lista *arr){
    ifstream arch("CamionesTortuninja.txt",ios::in); 
    int peso; 
    
    arch>>numcam;
    arch>>capLeo>>capRa>>capDon>>capMig; 
    
    for(int i=0; i<numcam; i++){
        construir(arr[i]); 
        while(true){
            arch>>peso; 
            if(peso==0) break;  
            
            insertarAlFinal(arr[i],peso);         
        }
    }
}

void imprimeCromo(int *cromo,int size){
    for(int i=0; i<size; i++){
        cout <<cromo[i]<<" ";
    }
    cout <<endl; 
}

bool validaMinimoTortuga(int *cromo, int size){
    
    for(int iTor = 0; iTor<4; iTor++){  // 0 1 2 3 -> por cada tortuga 
        int cant=0; 
        for(int i=0; i<size; i++){
            if(cromo[i]==iTor) cant++; 
        }
        //COMO MIN 1 CAMION Y MAXIMO 2 
        if(cant==0 or cant>2) return false; 
    }
    return true; 
}

void guardaCromoSolu(int *cromo,int *cromoSolu, int size){
    for(int i=0;i<size;i++){
        cromoSolu[i]=cromo[i];
    }
}

void imprimeSolucion(int *cromoSolu,int cantCamiones,
        struct Lista *arrLista){
    int bus1,bus2; //como maximo dos camiones 
    //POR CADA TORTUGA 
    for(int iTor=0;iTor<4;iTor++){
        nombreTortuga(iTor);
        int cantBusesTort = cuentaBusesXtortuga(cromoSolu,cantCamiones,iTor,
                bus1,bus2);
        //cout<<bus1 <<"  "<<bus2;
        if(cantBusesTort==1){
            imprime(arrLista[bus1]);    
        }
        else if(cantBusesTort==2){
            //cout<<"aun no"<<endl;
            ordenaBus(arrLista[bus1],cantCamiones,"-+");
            ordenaBus(arrLista[bus2],cantCamiones,"+-");
            //si quisiera que mi lista princ sea la mas chiqui
            int long1 = arrLista[bus1].longitud;
            int long2 = arrLista[bus2].longitud;
            if(long1<long2){
                unirBusesIntercalado(arrLista[bus1],arrLista[bus2]);
            }else{
                unirBusesIntercalado(arrLista[bus2],arrLista[bus1]);
            }
            imprime(arrLista[bus1]);
        }
    }
}
//en el de menor elemn se agrega
void unirBusesIntercalado(struct Lista &lista1, struct Lista lista2){
    struct Nodo*nodoLista2 = lista2.cabeza;
    int i=1;
    bool insertFinal=false;
    //recorro la lista 2 -> se inserta en lista 1
    while(nodoLista2){
        if(insertFinal==false and lista1.longitud>i){ //la longitud de L1 es variable 
            insertarEnIndice(lista1,nodoLista2->elemento,i);
            i=i+2; //avanza intercalado
        }
        //cuando i ya sobrepaso la long de L1
        else{ 
            insertarAlFinal(lista1,nodoLista2->elemento);
            insertFinal=true;
        }
        nodoLista2=nodoLista2->siguiente;
    }
    
}
    

void ordenaBus(struct Lista &lista,int cantCamiones,const char *ordenar){
    
    for(int i=0;i<lista.longitud-1;i++){
        for(int k=i+1;k<lista.longitud;k++){
            struct Nodo *nodo_i = BuscarNodo(lista,i);
            struct Nodo *nodo_k = BuscarNodo(lista,k);
            
            if(strcmp(ordenar,"+-")==0){
                if(nodo_i->elemento < nodo_k->elemento) cambiarNodos(nodo_i,nodo_k);
            }else if(strcmp(ordenar,"-+")==0){
                if(nodo_i->elemento > nodo_k->elemento) cambiarNodos(nodo_i,nodo_k);
            }
        }
    }
}



void cambiarNodos(struct Nodo *nodo_i,struct Nodo *nodo_k){
    //muy engorroso xd recuerda que son direcciones 
//    struct Nodo *aux;
//    aux = nodo_i;
//    nodo_i = nodo_k;
//    nodo_k = aux;
    {}
    //solo intercambiamos los valores :)
    int aux;
    aux = nodo_i->elemento;
    nodo_i->elemento = nodo_k->elemento;
    nodo_k->elemento = aux;
}

struct Nodo *BuscarNodo(struct Lista lista, int indice){
    struct Nodo *nodo = lista.cabeza;
    
    int i=0;
    while(nodo!=nullptr){
        if(indice ==i){
            return nodo;
        }else{
            nodo = nodo->siguiente;
            i++;
        }
    }
}

int cuentaBusesXtortuga(int *cromoSolu,int cantCamiones, int iTor,
        int &bus1,int &bus2){
    int cant=0;
    for(int i=0 ; i<cantCamiones ; i++){
        if(cromoSolu[i]==iTor){
            cant++;
            if(cant==1) bus1 = i;
            if(cant==2) bus2 = i;
        }
    }
    return cant;
}

void nombreTortuga(int iTor){
    if(iTor==0)cout <<endl<<"Leonardo: ";
    if(iTor==1)cout <<"Rafael : ";
    if(iTor==2)cout <<"Donatelo : ";
    if(iTor==3)cout <<"Miguel: ";
}
    

void fusionListas(struct Lista &lista1, struct Lista &lista2){
    //nodos para recorrer ambas listas 
    struct Nodo* nodoPrinc = lista1.cabeza; 
    struct Nodo *nodoSec = lista2.cabeza; 
    struct Nodo *anterior = nullptr; 
    //recorremos la lista secundaria para insertar ordenadamente en la lista principal 
    while(nodoSec!=nullptr){
        // 2 CASO -> vacio o no vaio 
        if(nodoPrinc!=nullptr){
            //hay elementos en la principal -> recorro ambas listas y comparo 
            if(nodoSec->elemento < nodoPrinc->elemento){
                //copiamos el nodo para evitar comparar directamente de la lista2
                struct Nodo* copiaNodoSec = crearNodo(nodoSec->elemento,nullptr); 
                anterior->siguiente = copiaNodoSec; 
                copiaNodoSec->siguiente = nodoPrinc; 
                anterior = copiaNodoSec; 
                lista1.longitud++; 
                //analizamos el sgt nodo SEC
                nodoSec = nodoSec->siguiente; 
                
            }else{ // HORA SEC > HORA PRINC (TA BIEN)
                //AVANZAMOS EN PRINCIPAL 
                anterior = nodoPrinc; 
                nodoPrinc = nodoPrinc->siguiente;  
            }
        }else{
            //la lista principal esta vacia  o
            //recorrimos toda la lista1 -> solo avanzar en la lista 2 y insertarlos en orden :)) 
            insertarEnOrden(lista1,nodoSec->elemento); 
            nodoSec = nodoSec->siguiente; 
        }
    }
}

void insertarEnIndice(struct Lista &lista,int elemento, int indice){
    struct Nodo *nuevoNodo = crearNodo(elemento,nullptr);
    struct Nodo*nodoIndAnt = obtenerNodoIndAnt(lista,indice);
    
    nuevoNodo->siguiente = nodoIndAnt->siguiente;
    nodoIndAnt->siguiente = nuevoNodo;
    lista.longitud++;
}

struct Nodo* obtenerNodoIndAnt(struct Lista &tad,int indice){
    struct Nodo * anterior = nullptr;
    struct Nodo * recorrido = tad.cabeza;
    
    int i=0;
    while ((recorrido != nullptr) and (i<indice)) { //cuando i==indice para  
        anterior = recorrido;
        recorrido = recorrido->siguiente;
        i++;
    }
    return anterior;
}