#include "stdio.h"
#define tmps 3620

int main(){
	
	int i;
	char h,m,s;
	
	h = m = s = 's';
	
	if(tmps/3600 <= 1) h = 0;
	if((tmps/60)%60 <= 1) m = 0;
	if(tmps%60 <= 1) s = 0;
	
	printf("%d seconde%c correspond à %d heure%c %d minute%c et %d seconde%c\n",tmps,s,tmps/3600, h, (tmps/60)%60, m, tmps%60, s);

  return 0;

}

