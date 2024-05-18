/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   preg1.h
 * Author: mell1
 *
 * Created on 14 de mayo de 2024, 12:21
 */

#ifndef PREG1_H
#define PREG1_H
void cargaBin(int num,int *cromo,int size,int base);
int obtienePesoLista(struct Lista &bus); 
void lecturaDatos(int &cantCamiones,int &capLeo,int &capRa,int &capDon,
        int &capMig, struct Lista *arr);
void imprimeCromo(int *cromo,int size);
bool validaMinimoTortuga(int *cromo, int size); 
bool validarCapacidad(int *cromo,int cantCamiones,struct Lista *arrLista,
        int capLeo,int capRa, int capDon,int capMig); 
void guardaCromoSolu(int *cromo,int *cromoSolu, int size);
void imprimeSolucion(int *cromoSolu,int cantCamiones,
        struct Lista *arrLista);
void nombreTortuga(int iTor);
int cuentaBusesXtortuga(int *cromoSolu,int cantCamiones, int iTor,
        int &bus1,int &bus2);
void ordenaBus(struct Lista &lista,int cantCamiones,
        const char *ordenar);
struct Nodo *BuscarNodo(struct Lista lista, int indice);
void cambiarNodos(struct Nodo *nodo_i,struct Nodo *nodo_k);
void insertarEnIndice(struct Lista &lista,int elemento, int indice);
struct Nodo* obtenerNodoIndAnt(struct Lista &tad,int indice);
void unirBusesIntercalado(struct Lista &lista1, struct Lista lista2);

void fusionListas(struct Lista &lista1, struct Lista &lista2);
#endif /* PREG1_H */

