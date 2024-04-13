#include <iostream>
#include <iomanip> 
#include <cmath> 
using namespace std;
#define MAXPROY 12
#define N 8

void cargaBin(int num,int cromo[N],int size,int base){
    int i=0,res;
    while(num>0){
        res = num %base;
        num = num/base;
        cromo[i]=res; 
        
        i++;
    }
}

int main(int argc, char** argv) {
    int n=8,p=250,cantPred,gananciaP,idPred,costoP,gananciaMax=-99999,bestNum;
    int proyectos[MAXPROY][5] = {{80,150,0,0,0}, 
                                {20,80,0,0,0},
                                {100,300,1,2,0},
                                {100,150,0,0,0},
                                {50,80,0,0,0},
                                {10,50,2,0,0},
                                {50,120,6,0,0},
                                {50,150,6,0,0}};
    
    //MEJOR SOLUCION -> GANANCIA MAX TOTAL -> NO SOBREPASAR P 
    int cromo[n]{},combinaciones=pow(2,n),bestCromo[n]{};
    bool noCumple;
    
    for(int i=0;i<combinaciones;i++){
        cargaBin(i,cromo,n,2); //base 2 pq se hace el proy o no 
//        for(int a=0;a<n;a++)cout <<cromo[a]; 
//        cout <<endl;
        gananciaP =0;
        costoP =0;
        noCumple = false; 
        for(int j=0;j<n;j++){ //recorre el cromo
            if(cromo[j]){
                gananciaP+= proyectos[j][1]; 
                costoP += proyectos[j][0];
                //DESCARTA LAS COMBINACIONES QUE NO CONSIDERAN ESOS PREDECESORES
                if(proyectos[j][2]!=0){ //tiene predecesores
                    //para el primero
                    if(proyectos[j][2]!=0 and cromo[proyectos[j][2]-1]==0){
                        noCumple = true;
                        break;
                    }
                    //para el seg
                    if(proyectos[j][3]!=0 and cromo[proyectos[j][3]-1]==0){
                        noCumple = true;
                        break;
                    }
                    //para el 3er
                    if(proyectos[j][4]!=0 and cromo[proyectos[j][4]-1]==0){
                        noCumple = true;
                        break;
                    }                    
                }
            }
        }
        //como guardo el q si cumple???
        if(noCumple==false and costoP<=p){
            if(gananciaMax<gananciaP){
                    gananciaMax = gananciaP;
                    bestNum = i; 
            }
        }
    }
    cout <<"Max ganan: "<<gananciaMax<<endl;
    cout <<"Proyectos: ";
    cargaBin(bestNum,bestCromo,n,2);
    for(int i=0;i<n;i++){
        if(bestCromo[i]) cout<< i+1<<" ";
    }
    
    return 0;
}
