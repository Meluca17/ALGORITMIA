#include <cstdlib>
#include <iostream>
#define N 6
#define M 6

using namespace std;

/*
 * 
 */

int cuentaHorizontal(int tablero[N][M],int m,int x, int y){
    if (y>=m){
        return 0;
    }
    else {
        return tablero[x][y] + cuentaHorizontal(tablero,m,x,y+1);
    }
}

int cuentaVertical(int tablero[N][M],int n,int x,int y){
    if (x>=n){
        return 0;
    }
    else {
        return tablero[x][y] + cuentaVertical(tablero,n,x+1,y);
    }
}

int cuentaMinas(int tablero[N][M],int n,int m,int x,int y,int dx,int dy){
    int minas;
    if ((y>=m || y<0) || (x>=n || x<0)){
        //Aqui es el caso base
        if (dx==0){ //Aqui me muevo de forma horizontal (Derecha, Izquierda)
            minas = cuentaHorizontal(tablero,m,x,0);
        }
        else {
            /*Aqui me muevo de forma vertical (arriba, abajo)*/
            minas = cuentaVertical(tablero,n,0,y);
        }
        return minas;
    }
    else {
        if (dx==0){
            minas = cuentaVertical(tablero,n,0,y);
        }
        else {
            minas = cuentaHorizontal(tablero,m,x,0); 
        }
        minas = minas - tablero[x][y];
        return minas + cuentaMinas(tablero,n,m,x+dx,y+dy,dx,dy);
    }
}

int main(int argc, char** argv) {

    int tablero[N][M] = {{0,0,0,1,0,1},
                         {0,0,1,0,0,0},
                         {0,1,0,0,0,1},
                         {1,0,0,0,0,0},
                         {0,1,0,0,0,0},
                         {0,0,0,0,1,0}};
   
    int n=6, m=6, x=3, y=2;
    int dx=0, dy=-1; /*El movimiento lo colocamos en funcion del desplazamiento, en este caso es derecha*/
    
    cout << cuentaMinas(tablero,n,m,x,y,dx,dy);
    return 0;
}
