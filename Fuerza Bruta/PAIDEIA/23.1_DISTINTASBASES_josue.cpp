/* 
 * File:   main.cpp
 * Author: W10
 *
 * Created on 15 de agosto de 2023, 11:07 AM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
void cargaBin(int num,int n,int cromo[], int base){
    int res, i=0;
    for(int j=0; j<n; j++)cromo[j]=0;
        while(num>0){
            res= num%base;
            num=num/base;
            cromo[i]=res;
            i++;  
        }
}
// quitÃ© la posibilidad de que haya un camiÃ³n vacÃ­o
int main(int argc, char** argv) {
    int c=4,n=5,opcion; 
    int camiones[]={25,50,100,100};   
    int camionesAux[c];
    int paq[]={50,20,30,50,20};
    int cromo[n];
    int min,max,comb,resta,restaMin=99999999;
    opcion= pow(c,n);
    for(int i=0;i<opcion;i++){
        cargaBin(i,n,cromo,c);
        for(int j=0;j<c;j++)camionesAux[j]=camiones[j];
        for(int j=0;j<n;j++){
               camionesAux[cromo[j]]= camionesAux[cromo[j]]- paq[j]; 
        }
        min=camionesAux[0];
        max=camionesAux[0];
        for(int j=0;j<c;j++){
            if(camionesAux[j]<min){
                min= camionesAux[j];
            }
            if(camionesAux[j]>max){
                max= camionesAux[j];
            }  
        }
        if(max>=0 && min>=0){ // valido que la carga disponible de un camion no sea negativa
           resta=max-min;
        }
        if(restaMin>resta){
            restaMin=resta;
            comb=i;
        }
    } 
    cout<<restaMin<<endl;
    cargaBin(comb,n,cromo,c);
    for(int i=0;i<n;i++){
        cout<<"paquete"<<i+1<<" camion:"<<cromo[i]+1<<endl;
    }
    return 0;
}
