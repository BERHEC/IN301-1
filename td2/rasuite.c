#include "stdio.h"
#define e 0.00001

int diff(double a, double b){

	if(a - b < 0){ if(b - a < e) return 0;
		else return -1;}
	if(a - b > 0){ if(a - b < e) return 0;	
		else return 1;}
		
}

double racine(double n){
	
	double g,d,m;
	double gb,db;
	int i;

	d=n;
	g=0;
	
	do{ 		
		gb=g; db=d;	
		m = (d+g)/2.0; 
		i = diff((m*m), n);
		
		if(!i)break;
		
		if(i>0)d=m; // m*m> n
		if(i<0)g=m; // m*m < n
		

				
		}while((gb != g) || (db != d));

	return d;

}


int main(){
	
	int i,n;
	double S = 0.0;
	
	scanf("%d", &n);
	
	for(i = n; i >= 1; i--)
		S = racine(i+S);
	
	printf("%f\n",S);
	
	

    return 0;

}

