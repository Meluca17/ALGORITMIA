/* 
 * File:   Lista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:51 PM
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
struct Lista {
    struct Nodo * cabeza; /*apunta al inicio de la lista*/
    int longitud; /*guarda la longitud de la lista*/
    int pesoTotal;
    struct Nodo *cola;
};

#endif /* LISTA_H */

