// -*- C++ -*-

/* 
 * File:   funcionesABB.h
 * Author: ANA RONCAL
 *
 * Created on 30 de mayo de 2024, 15:54
 */

#ifndef FUNCIONESABB_H
#define FUNCIONESABB_H

void construir(struct ArbolBinarioBusqueda & arbol);
void insertar(struct ArbolBinarioBusqueda & arbol, int elemento);
void insertarRecursivo(struct NodoArbol *& nodo, int elemento);
void enOrden(const struct ArbolBinarioBusqueda & arbol);
void plantarArbolBB(struct NodoArbol *& nodo, struct NodoArbol * arbolIzquierdo,
         int elemento, struct NodoArbol * arbolDerecha);
bool buscaArbol(const struct ArbolBinarioBusqueda & arbol, int dato);
bool buscaArbolRecursivo(struct NodoArbol * nodo, int dato);
int comparaABB(int elementoA, int elementoB);
void eliminarNodo(struct ArbolBinarioBusqueda & arbol, int dato);
struct NodoArbol * eliminarNodoRecursivo(struct NodoArbol * nodo, int elemento);
void destruirArbolBB(struct ArbolBinarioBusqueda & arbol);
#endif /* FUNCIONESABB_H */