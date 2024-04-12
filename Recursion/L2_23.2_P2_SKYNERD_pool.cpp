/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: usuario
 *
 * Created on 10 de abril de 2024, 16:31
 */

#include <cstdlib>
#include <iostream>
#define N 7
using namespace std;
int posSkyNerd=0;
int contadorSky=0;
int servidor[N][N]={    { 0, 0, 0, 0, 0, 0, 0 },
                        {10, 0, 20,30, 0,20,30},
                        { 0, 0, 0, 0, 0,100, 0},
                        { 0, 0, 0, 0, 0,80, 0 },
                        {50,10, 5,10, 0,100, 10},
                       {100, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0 }
 };                       
bool detectarSkyNerd(int i,int serv_ini){
    if(contadorSky==N){
    	posSkyNerd=serv_ini+1;
    	return true;
    }
    if(serv_ini==N){
    	return false;
    }

    
	if(servidor[i][serv_ini]==0){
		contadorSky++;
		detectarSkyNerd(i+1,serv_ini);
	}else{
		contadorSky=0;
		detectarSkyNerd(0,serv_ini+1);	
	}

}


int main(){
	
    int serv_ini=0,i=0;
    if(  detectarSkyNerd(i,serv_ini)  )
        cout << "SkyNerd ha sido detectado en el servidor " <<posSkyNerd;
    else
        cout << "SkyNerd no se encuentra en la red";
    cout << endl;
	return 0;
	
}
