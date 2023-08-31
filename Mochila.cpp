#include <iostream>
#include <cmath>

using namespace std;




void cargabin(int num,int cromo[],int n){
	int res,i=0;
	
	while(num>0){
		res=num%2;
		num=num/2;
		cromo[i]=res;
		i++;
	}
}



int main(){
	int n=5,peso=15;
	int paq[]={1,2,4,12,1};
	int cromo[n];
	
	int opcion=(int)pow(2,n);
	
	for(int i=0;i<opcion;i++){
		int pparcial=0;
		cargabin(i,cromo,n);
		for(int j=0;j<n;j++){
			pparcial=cromo[j]*paq[j]+pparcial;
		}	
		if(pparcial==peso){
			cout <<"La solucion es:"<< i <<endl;
			for(int j=0;j<n;j++){
				cout << cromo[j]*paq[j]<<" ";
			}	
			cout << endl;
		}		
	}
	return 0;
}

