#include "stdio.h"
#define e 0.00001

int nmax;

int Syracuse (int u, int i){

		printf("%d\n", u);
		
		if(i >= nmax)
			return i;
		
		if(u == 1)
			return i;
		
		if(u%2) u = 3*u + 1;
		else u = u/2;
		
		Syracuse(u, ++i);
	
	
}


int main(){
	
	int i,n;
	
	scanf("%d", &n);
	scanf("%d", &nmax);
	printf("---\n");

	i = Syracuse(n, 1);
	
	printf("Nombre d'itérations: %d\n", i);

    return 0;

}

