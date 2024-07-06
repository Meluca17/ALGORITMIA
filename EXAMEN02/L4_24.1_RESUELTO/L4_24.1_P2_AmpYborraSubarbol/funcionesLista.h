/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

struct Nodo * crearNodo(NodoArbol *elemento, struct Nodo *);
NodoArbol *  retornaCabeza(const struct Lista &);
void insertarencola(struct Lista & tad, NodoArbol *elemento);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista &);

#endif /* FUNCIONESLISTA_H */

