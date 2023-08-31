#include <iostream>
#include <cmath>

using namespace std;

void cargabin(int num,int cromo[],int n){
	int res,i=0;
	for(int k=0;k<n;k++)cromo[k]=0;
	while(num>0){
		res=num%2;
		num=num/2;
		cromo[i]=res;
		i++;
	}
}



int main(){
	int n=8,peso=25,mpeso=0,mcomb,mgana=0;
	int paq[][2]={{8,10},{2,20},{1,5},{4,9},{5,8},{5,5},
	{10,10},{4,6}};
	int cromo[n];
	//Maxima ganacia  Restriccion: n<10 no superar el peso
	int opcion=(int)pow(2,n);
	
	for(int i=0;i<opcion;i++){
		int pparcial=0;
		int ganancia=0;		
		cargabin(i,cromo,n);
		
		for(int j=0;j<n;j++){
			pparcial+=cromo[j]*paq[j][0];
			ganancia+=cromo[j]*paq[j][1];
		}	
		if(mgana<ganancia && pparcial<=peso){
			mgana = ganancia;
			mcomb=i;

		}		
	}
	cout <<"La solucion es:"<< mgana <<endl;
	cargabin(mcomb,cromo,n);
	for(int j=0;j<n;j++)
		cout << cromo[j]*paq[j][0]<<" ";	
	cout << endl;
	for(int j=0;j<n;j++)
		cout << cromo[j]*paq[j][1]<<" ";	
	cout << endl;
			
	return 0;
}

