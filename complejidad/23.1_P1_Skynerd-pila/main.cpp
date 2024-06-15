
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 10 de junio de 2024, 15:20
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <codecvt>
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;
#define N 7
#define M 7
#define A 8

void leeDatos(const char *filename,int servidor[N][M],int &n,int &m);
bool buscarSkynerd(int servidor[N][M],int n,int m,int &idServidor); 
void imprimeArreglo(int *array,int n);
int *calcularIntervalos(int *contagios,int n);
int *encontrarIntervalos(int input[],int n);
/*
 *  SKYNERD CON PILA -> O(n) -> una iterativa 
 */

int main(int argc, char** argv) {
    int servidor[N][M], n,m,idServidor=0; 
    bool estaSkynerd; 
    
    leeDatos("datos1.txt",servidor,n,m); 
    estaSkynerd = buscarSkynerd(servidor,n,m,idServidor);
//    if(estaSkynerd)cout <<"Se encuentra en el servidor n° "<<idServidor<<endl<<endl;
//    else cout <<"No se encuentra"<<endl<<endl;
    
    //////////////////////// MINSA /////////////////////////////////////
    int contagios[A]={10, 20, 15, 10, 12, 10, 13, 18};
    int  *intervalos,numCont = 8;
    intervalos = calcularIntervalos(contagios,numCont);
    imprimeArreglo(intervalos,numCont);
    
    return 0;
}


///////////////////////// SKYNERD ///////////////////////////////////////////////
void imprimeArreglo(int *array,int n){
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
void leeDatos(const char *filename,int servidor[N][M],int &n,int &m){
    ifstream arch(filename,ios::in);
    arch>>n>>m; 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arch>>servidor[i][j];
        }
    }
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout<<servidor[i][j]<<" ";
//        }
//        cout <<endl; 
//    }
//0 0 0 0 0 0 0 
//10 0 20 30 0 20 40 
//0 0 0 0 0 100 0 
//0 0 0 0 0 80 0 
//50 10 5 10 0 100 4 
//100 0 0 0 0 0 0 
//0 0 0 0 0 0 0 
}
//SKYNERD envia a TODOS
//NO RECIBE ninguno 
bool buscarSkynerd(int servidor[N][M],int n,int m,int &idServidor){
    Pila pilaIDs;
    construir(pilaIDs);
    for(int i=0;i<n;i++)apilar(pilaIDs,i); //construye los ids
    
    //verificamos de pares EL ENVIO 
    //descartamos el servidor porque está recibiendo y skynerd no recibe
    while(pilaIDs.lista.longitud >1){
        int a = desapilar(pilaIDs);
        int b = desapilar(pilaIDs);
        if(servidor[a][b]!=0)// envio
            apilar(pilaIDs,a);
        else 
            apilar(pilaIDs,b);
    }
    int candidato = desapilar(pilaIDs); //solo me quedo con un dato
    for(int i=0;i<n;i++){ //verifica que cumpla ambas condiciones :)
        if((servidor[candidato][i]==0 or servidor[i][candidato]!=0) 
                and (i!=candidato)){
            return false;
        }
    }
    idServidor = candidato+1;
    return true;
} 

///////////////////////// MINSA ///////////////////////////////////////////////
int *calcularIntervalos(int *contagios,int n){
    int *interavalos = new int [n], temp;
    Pila pila;
    construir(pila);
    for(int i=0;i<n;i++){ //recorro cada indice de dia 
        //condicion para desapilar cuando sea mayor (creo)
        while(!esPilaVacia(pila) and contagios[cima(pila)] <=contagios[i]){
            temp = desapilar(pila);
        }
        //guarda el intervalo y apila
        if(!esPilaVacia(pila)){
            interavalos[i] = i-cima(pila)-1;
        }else{
            interavalos[i] = i; //cuando la pila esta vacia 
        }
        apilar(pila,i);
    }
    return interavalos;
}

///////////////////////// TEMPERATURA ///////////////////////////////////////////////
//intervalos de cuantos dias faltan para encontrar una temperatura mayor 
int *encontrarIntervalos(int input[],int n){
    int *intervalo=new int[n]{};
    struct Pila pila;
    construir(pila);
    
    for(int i=0;i<n;i++){
        while(!esPilaVacia(pila) and input[i]>input[cima(pila)]){
            int topIndex=desapilar(pila);
            intervalo[topIndex]=i-topIndex;
        }
        apilar(pila,i);
    } //O(n), 
    
    return intervalo;
}