/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcBatalla.h
 * Author: mell1
 *
 * Created on 16 de mayo de 2024, 23:04
 */

#ifndef FUNCBATALLA_H
#define FUNCBATALLA_H
using namespace std;
void leeDatos(const char * nombArchText, struct Lista & tad,
        int &n, int &numGuerr);
void formarEjercito(int numGuer,struct Lista listaIni,
        struct Lista &ejBowser,struct Lista &ejPeach,struct Lista &ejDonkey);
void imprimeEjercitos(struct Lista &ejercitoBowser,struct Lista &ejercitoPeach,
        struct Lista &ejercitoDonkey);
void fusionar(struct Lista &lista1,struct Lista &lista2);

Nodo* obtenerNodoEnPosicion(Lista &tad, int posicion) ;
void muestraPelea(struct Lista &ejBowser,struct Lista &ejPeach,int indNodo,
        bool &pierdePeach, bool &pierdeBowser);
void simulaBatalla(int numPeleas,struct Lista ejBowser,struct Lista ejPeach,
        struct Lista ejDonkey);
void eliminaCabeza(struct Lista &tad);
void eliminaGuerreros(struct Lista &ejBowser,struct Lista &ejPeach,bool pierdePeach,
        bool pierdeBowser);
void llamaRefuerzos(struct Lista &ejPeach,struct Lista &ejDonkey,bool &unaVez);
void determinarGanador(struct Lista &ejPeach,struct Lista &ejBowser);
#endif /* FUNCBATALLA_H */

