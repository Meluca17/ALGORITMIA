
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 14 de junio de 2024, 23:55
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#define N 15

int cuentaCeros(int *array,int ini,int fin, int cont);
int cuentaUnos(int *array,int ini,int fin, int cont);
/*
 * 
 */
int main(int argc, char** argv) {
    int array[N] =  {1, 1, 1, 1, 0, 0, 0};
    int n=7;
    cout <<"Ceros: "<< cuentaCeros(array,0,n-1,0)<<endl;
    cout <<"Unos: "<< cuentaUnos(array,0,n-1,0);
    
    
    return 0;
}

int cuentaUnos(int *array,int ini,int fin, int cont){
    if(ini>fin) return cont;
    
    int med = (ini+fin)/2;
    if(array[med]==0){
        return cuentaUnos(array,ini,med-1,cont);
    }else{
        return cuentaUnos(array,med+1,fin,cont+(med-ini+1));
    }
}

int cuentaCeros(int *array,int ini,int fin, int cont){
    if(ini>fin) return cont;
    
    int med = (ini+fin)/2;
    if(array[med]==1){
        return cuentaCeros(array,med+1,fin,cont);
    }
    else{
        //no toma en cuenta el medio porque ya lo suma con el +1
        return cuentaCeros(array,ini,med-1,cont+(fin-med+1));
    }
}
