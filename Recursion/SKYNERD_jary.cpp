#include <iostream>
#include <iomanip> 
using namespace std;
#define N 7
#define M 7

int buscarSkynerd(int red[N][M],int posX,int posY,int n,int m){
    if(posX==n) return posY+1; 
    //no hubo nd
    if(posY==n) return 0; 
    
    
    if(red[posX][posY]==0){
        buscarSkynerd(red,posX+1,posY,n,m); //BAJO
    }else{
        buscarSkynerd(red,0,posY+1,n,m); //busco columna  
    }
    
}

int main(int argc, char** argv) {
    int red[N][M] = {
                    {0,10,10,10,20,10,10},
                    {10,0,20,30,0,20,40},
                    {0,0,0,0,0,100,0},
                    {0,0,0,0,0,80,0},
                    {50,10,5,10,0,100,4},
                    {100,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0},
                    }; 
    int n=7, m=7; 
    int estaSkynerd; 
    
    estaSkynerd = buscarSkynerd(red,0,0,n,m);
    
    cout <<"Skynerd es la red "<<estaSkynerd<<endl; 
    return 0; 
}
