/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Lista.h"
#include "funciones.h"
#include "funcBatalla.h"
using namespace std;

void leeDatos(const char * nombArchText, struct Lista & tad,int &n, int &numGuerr){
    ifstream archText(nombArchText, ios::in);
    if (not archText.is_open()) {
        cout << "ERROR: No se puede abrir el archivo";
        exit(1);
    }
    
    int elemento;
    
    archText>>n>>numGuerr;
    while (true) {
        archText>>elemento;
        if (archText.eof()) break;
         //lee el elemento del archivo
        insertarAlFinal(tad, elemento);
    }
}

void formarEjercito(int numGuer,struct Lista listaIni,
        struct Lista &ejBowser,struct Lista &ejPeach,struct Lista &ejDonkey){
    int tipoEj,nivelAtaque;
    struct Nodo *recOrigen = listaIni.cabeza;
    
    //recorremos la lista 1
    while(recOrigen){
        tipoEj = (recOrigen->elemento)%10;
        nivelAtaque = (recOrigen->elemento)/10;
        //BOWSER
        if(tipoEj==1){
            insertarEnOrden(ejBowser,nivelAtaque);
        }
        //PEACH
        else if(tipoEj==2){
            insertarEnOrden(ejPeach,nivelAtaque);
        }
        //DONKEY KONG
        else{
            insertarEnOrden(ejDonkey,nivelAtaque);
        }
        
        //avanza
        recOrigen = recOrigen->siguiente;
    }
}

void imprimeEjercitos(struct Lista &ejercitoBowser,struct Lista &ejercitoPeach,
        struct Lista &ejercitoDonkey){
    cout <<endl<<"Ejercito 1-Bowser: ";
    imprime(ejercitoBowser);
    cout<<"Nivel de Ataque Total del Ejército 1: "
            <<ejercitoBowser.ataqueTotal<<endl<<endl;
    
    cout <<"Ejercito 2-Peach: ";
    imprime(ejercitoPeach);
    cout<<"Nivel de Ataque Total del Ejército 2: "
            <<ejercitoPeach.ataqueTotal<<endl<<endl;
    
    cout <<"Ejercito 1-Donkey: ";
    imprime(ejercitoDonkey);
    cout<<"Nivel de Ataque Total del Ejército 3: "
            <<ejercitoDonkey.ataqueTotal<<endl<<endl;
    
    //cout<<"cola peach: "<<ejercitoPeach.cola->elemento;
}
//LISTAS: ordenadas de mayor a menor
// TIENE 3 CASOS
void fusionar(struct Lista &lista1,struct Lista &lista2){
    lista1.ataqueTotal += lista2.ataqueTotal;
    // COLA1 < CAB2
    if(lista1.cola->elemento < lista2.cabeza->elemento){
        lista1.cola->siguiente = lista2.cabeza;
        lista1.cola = lista2.cola;
    }
    // COLA2 < CAB1
    else if(lista2.cola->elemento < lista1.cabeza->elemento){
        lista2.cola->siguiente = lista1.cabeza;
        lista1.cabeza = lista2.cabeza;
    }
    // TODO INTERCALADO 
    else{
        //nodos que indiquen el inicio y el fin 
        struct Nodo *inicio=nullptr;
        struct Nodo *fin=nullptr;
        //recorremos la lista
        while(!esListaVacia(lista1) and !esListaVacia(lista2)){
            // elem1 < elem2
            if(lista1.cabeza->elemento < lista2.cabeza->elemento){
                //si es el inicio asignamos nodo ini y nodo fin
                if(inicio==nullptr){
                    inicio = lista1.cabeza;
                    fin = lista1.cabeza;
                }
                else{
                    fin->siguiente = lista1.cabeza;
                    fin = lista1.cabeza;
                }
                lista1.cabeza = lista1.cabeza->siguiente;
            }
            // elem2 < elem1
            else{
                //si es el inicio asignamos nodo ini y nodo fin
                if(inicio==nullptr){
                    inicio = lista2.cabeza;
                    fin = lista2.cabeza;
                }
                else{
                    fin->siguiente = lista2.cabeza;
                    fin = lista2.cabeza;
                }
                lista2.cabeza = lista2.cabeza->siguiente;
            }
        }
        //pueden quedar nodos en una lista 
        if(not esListaVacia(lista1)){
            fin->siguiente = lista1.cabeza;
            fin = lista1.cola;
        }
        if(not esListaVacia(lista2)){
            fin->siguiente = lista2.cabeza;
            fin = lista2.cola;
        }
        lista1.cabeza = inicio;
        lista1.cola = fin;
    }
    
}

//
void simulaBatalla(int numPeleas,struct Lista ejBowser,struct Lista ejPeach,
        struct Lista ejDonkey){
    bool pierdePeach, pierdeBowser, unaVez=true;
    //se seguira haciendo hasta q alguno ya no tenga guerreros
    while(true){
        if(esListaVacia(ejBowser) or esListaVacia(ejPeach)) break;
        
        cout<<"Inicio de la batalla: "<<endl;
        pierdeBowser = false;
        pierdePeach = false;
        for(int i=0;i<numPeleas;i++){
            muestraPelea(ejBowser,ejPeach,i,pierdePeach,pierdeBowser);
        }
        eliminaGuerreros(ejBowser,ejPeach,pierdePeach,pierdeBowser);
        cout<<"Nivel de ataque Total Del Ejercito 1: "<<ejBowser.ataqueTotal<<endl;
        cout<<"Nivel de ataque Total Del Ejercito 2: "<<ejPeach.ataqueTotal<<endl;
        if(unaVez and pierdePeach){
            llamaRefuerzos(ejPeach,ejDonkey,unaVez);
//            imprime(ejPeach);
//            return;
        } else{
            cout<<"Ya no se puede unir nadie al ejército de Peach. "<<endl;
        }
        int long1 = ejBowser.longitud;
        int long2 = ejPeach.longitud;
    }    
    
    determinarGanador(ejBowser,ejPeach);
}

void muestraPelea(struct Lista &ejBowser,struct Lista &ejPeach,int indNodo,
        bool &pierdePeach, bool &pierdeBowser){
    //hallo los nodos que queremos analizar
    struct Nodo *nodoBowser = obtenerNodoEnPosicion(ejBowser,indNodo);
    struct Nodo *nodoPeach = obtenerNodoEnPosicion(ejPeach,indNodo);
    if(nodoPeach==nullptr or nodoBowser==nullptr) return; //retorna en caso solo haya una pelea y el sgte nodo de peach sea 0
    
    cout<<"Pelea "<<indNodo+1<<": ";
    cout<<nodoBowser->elemento<<" vs. "<<nodoPeach->elemento<<" ,gana ";

    //gana bowser -> elimino peach
    if(nodoBowser->elemento>nodoPeach->elemento){
        cout<<nodoBowser->elemento<<endl;
        pierdePeach = true;
    }
    else{
        cout<<nodoPeach->elemento<<endl;
        pierdeBowser = true;
        //eliminaCabeza(ejBowser);
    }
    
}

void eliminaGuerreros(struct Lista &ejBowser,struct Lista &ejPeach,bool pierdePeach,
        bool pierdeBowser){
    //cout<<pierdeBowser<<"  "<<pierdePeach;
    if(pierdeBowser){
        //elimina 2 veces porque las batallas se dan de dos en 2
        eliminaCabeza(ejBowser);
        if(!esListaVacia(ejBowser)){
            eliminaCabeza(ejBowser);
        }
    }
    else if(pierdePeach){
        eliminaCabeza(ejPeach);
        if(!esListaVacia(ejPeach)){
            eliminaCabeza(ejPeach);
        }
    }
}

void llamaRefuerzos(struct Lista &ejPeach,struct Lista &ejDonkey,bool &unaVez){
    cout<<"El ejército de DonKey Kong se une al ejército de Peach."<<endl;
    fusionar(ejPeach,ejDonkey);
    unaVez = false;
}

void determinarGanador(struct Lista &ejBowser,struct Lista &ejPeach){
    //gana la batalla el que siga teniendo guerreros
    if(!esListaVacia(ejBowser)){
        cout<<endl<<"Gana la batalla Bowser. "<<endl;
    }else if(!esListaVacia(ejPeach)){
        cout<<endl<<"Gana la batalla Peach. "<<endl;
    }
}

//struct Lista {
//    struct Nodo * cabeza; /*apunta al inicio de la lista*/
//    struct Nodo *cola;
//    int longitud; /*guarda la longitud de la lista*/
//    int ataqueTotal;
//};
void eliminaCabeza(struct Lista &tad){
    struct Nodo *primerNodo = tad.cabeza;
    tad.cabeza = tad.cabeza->siguiente;
    
    tad.ataqueTotal -= primerNodo->elemento;
    //tad.longitud--;
}

Nodo* obtenerNodoEnPosicion(Lista &tad, int posicion) {
    // Verificar si la posición es válida
    if (posicion < 0) {
        return nullptr; // Retornar nullptr si la posición es inválida
    }
    
    Nodo* actual = tad.cabeza;
    int contador = 0;

    // Recorrer la lista hasta llegar a la posición deseada o al final de la lista
    while (actual != nullptr && contador < posicion) {
        actual = actual->siguiente;
        contador++;
    }

    // Si hemos llegado al final de la lista, retornar nullptr
    if (actual == nullptr) {
        return nullptr;
    }

    return actual; // Retornar el nodo en la posición especificada
}