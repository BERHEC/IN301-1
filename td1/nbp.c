#include "stdio.h"


int main(){
	
	int n;
	int i;
	
	scanf("%d", &n);
	
	for (i = 2; i < n - 1; i++)
	{
		if((n%i == 0)) {printf("%d n'est pas un nombre premier\n", n); return 0;}
		
	}
	
	printf("%d est un nombre premier\n", n);
	

  return 0;

}

