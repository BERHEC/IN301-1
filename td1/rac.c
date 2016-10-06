#include "stdio.h"
#define e 0.00001


int diff(double a, double b){

	if(a - b < 0){ if(b - a < e) return 0;
		else return -1;}
	if(a - b > 0){ if(a - b < e) return 0;	
		else return 1;}
		
}

int main(){
	
	double g,d,m;
	double gb,db;
	int i,n;
	
	scanf("%d", &n);
	d=n;
	g=0;
	
	do{ 		
		gb=g; db=d;	
		m = (d+g)/2.0; 
		i = diff((m*m),(float)n);
		
		if(!i)break;
		
		if(i>0)d=m; // m*m> n
		if(i<0)g=m; // m*m < n
		
		printf("%f-%f\n",g,d);
				
		}while((gb != g) || (db != d));

	printf("La racine carrée de %d est %f.\n", n, d);

  return 0;

}

