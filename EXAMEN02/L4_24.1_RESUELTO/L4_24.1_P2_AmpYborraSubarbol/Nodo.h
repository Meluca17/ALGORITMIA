/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 12:00 PM
 */
 

#ifndef NODO_H
#define NODO_H
#include "NodoArbol.h"

struct Nodo{
    struct NodoArbol *elemento; 
    struct Nodo *siguiente; 
};

#endif 
