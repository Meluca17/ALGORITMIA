
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 12 de junio de 2024, 9:02
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <complex>
using namespace std;
#define N 10
#define M 10

int hallaMaxDescartando(int *arreglo,int ini,int fin);
int sinpareja(int *array,int ini,int fin);
int hallaMenor(int matriz[N][M],int i,int ini,int fin);
/*
 * 
 */
int main(int argc, char** argv) {
    int arreglo[N] = {10,13,15,19,20,22,25};
    int n=7;
    int pareitas[N] = {2,2,3,3,4,4};
    int n2=6; 
    int calorias[N][M] = {{12,7,9,5,18},
                                    {3,7,2,10,20},
                                    {25,12,7,8,19},
                                    {3,7,2,10,20},
                                    {3,7,2,10,20}};
    int n3=5,m3=5;
    
    //cout << "El maximo es: "<<hallaMax(arreglo,0,n-1)<<endl; 
    //cout <<"El numero sin pareja es: "<<sinpareja(pareitas,0,n2-1); 
    
    //COMPLEJIDAD: O(n) = n * m*log(m)
    for(int i=0;i<n3;i++){
        cout <<"Menor caloria "<<hallaMenor(calorias,i,0,m3-1)<<endl;
    }
    
    return 0;
}

// COMPLEJIDAD -> O(n) = log(n) -> ya que descarta 
int hallaMaxDescartando(int *arreglo,int ini,int fin){
    //caso base 
    if(ini>=fin){
        return arreglo[ini]; 
    }
    int med = (ini+fin)/2; 
    //DESCARTA 
    if(arreglo[med] > arreglo[med+1]){ //descarta derecha
        return hallaMaxDescartando(arreglo,ini,med); 
    }else{
        return hallaMaxDescartando(arreglo,med+1,fin); 
    }
}

//COMPLEJIDAD -> O(n) = log(n) -> va descartando 
int sinpareja(int *array,int ini,int fin){
    if(ini>fin) return -1;
    if(ini==fin){
        return array[ini]; 
    }
    int med = (ini+fin)/2; 
    
    if(med%2==0){//par -> abarca 0
        if(array[med] == array[med+1]){ 
            return sinpareja(array,med+2,fin); 
        }else{
            return sinpareja(array,ini,med); 
        }
    }else{ //impar -> abarca 1
        if(array[med-1] !=array[med]){
            return sinpareja(array,ini,med-1); 
        }else{
            return sinpareja(array,med+1,fin); 
        }
    }
}

//COMPLEJIODAD -> O(n)= m*log(m)
int hallaMenor(int matriz[N][M],int i,int ini,int fin){
    if(ini==fin) return matriz[i][ini];
    int med = (ini+fin)/2;
    //avanzamos
    int izq = hallaMenor(matriz,i,ini,med);
    int der =hallaMenor(matriz,i,med+1,fin);
    if(izq<der) return izq;
    else return der;
}

//jhfkhg