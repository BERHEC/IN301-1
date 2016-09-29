#include "stdio.h"
#define e 0.001


int main(){
	
	double n,m;
	int i,d,f;
	
	scanf("%d", &n);
	m=n;
	
	while((m/2.0)*(m/2.0) > m){ m = m / 2; printf("%d",m);}

	
	printf("La %d est un nombre premier\n", n);
	

  return 0;

}

