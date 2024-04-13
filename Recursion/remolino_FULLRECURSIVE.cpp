
#include <cstdlib>
#include <iostream>
#define N 5
#define M 5

using namespace std;

void impresion1(int tablero[N][M],int x,int y,int m){
    if (y>=m){
        return ;
    }
    cout << tablero[x][y] << " ";
    impresion1(tablero,x,y+1,m);
}

void impresion2(int tablero[N][M],int y,int x,int n){
    if (x>=n){
        return ;
    }
    cout << tablero[x][y] << " ";
    impresion2(tablero,y,x+1,n);
}

void impresion3(int tablero[N][M],int x,int y,int limy){
    if (y<limy){
        return ;
    }
    cout << tablero[x][y] << " ";
    impresion3(tablero,x,y-1,limy);
}

void impresion4(int tablero[N][M],int x,int y,int limx){
    if (x<limx){
        return ;
    }
    cout << tablero[x][y] << " ";
    impresion4(tablero,x-1,y,limx);
}

void imprimeTablero(int tablero[N][M],int n,int m,int x,int y){
    if (y>m){
        /*Caso base*/
        return ;
    }
    /*Impresion 1*/
    impresion1(tablero,x,y,m);
    cout << endl;
    impresion2(tablero,m-1,y+1,n);
    cout << endl;
    impresion3(tablero,n-1,m-2,y);
    cout << endl;
    impresion4(tablero,n-2,y,x+1);
    cout << endl;
    imprimeTablero(tablero,n-1,m-1,x+1,y+1);
}

/*
 * 
 */
int main(int argc, char** argv) {
    int tablero[N][M];
    int n=4, m=5, valor=1;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            tablero[i][j] = valor++;
        }
    }
    imprimeTablero(tablero,n,m,0,0);
    return 0;
}
