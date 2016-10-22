#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct Tableau{
	int tab[100];
	int taille;	
	
};

typedef struct Tableau TB;

int alea(int n)
{
	return rand()%n;		
}

TB remplinit(TB t, int taille, int n){
	int i;
	t.taille = taille;
	for (i=0; i<t.taille; i++)
		t.tab[i] = alea(n);	
	return t;
}

void affichtab(TB t){
	int i;
	for (i=0; i<t.taille; i++)
		printf("(%d)", t.tab[i]);
	printf("\n");
}

long int prodtab(TB t){
	int i;
	long int p = 1;
	for (i=0; i<t.taille; i++)
		p *= t.tab[i];
	return p;
}

long int sommtab(TB t){
	int i;
	long int p = 0;
	for (i=0; i<t.taille; i++)
		p += t.tab[i];
	return p;
}

int mintab(TB t, int d){
	int i;
	int m = d; //  sinon problème avec la dernière valeur;
	for (i=d; i<t.taille; i++)
		if (t.tab[m] > t.tab[i]) m = i;
	return m;
}


int maxtab(TB t, int d){
	int i;
	int m = d;
	for (i=d; i<t.taille; i++)
		if (t.tab[m] < t.tab[i]) m = i;
	return m;
}

TB ins0gtab(TB t){
	int i;
	int m = t.tab[0];
	if(t.taille + 1 > 100) return t;
	for (i=t.taille; i>=0; i--)
		t.tab[i+1] = t.tab[i];
	t.tab[0] = 0;
	t.taille++;
	return t;
}

TB swap (TB t, int i, int j){
	int temp;
	temp = t.tab[i];
	t.tab[i] = t.tab[j];
	t.tab[j] = temp;
	return t;	
}

TB tinverse(TB t){
	int i;
	for(i=0; i<t.taille/2; i++){
	t = swap(t,i, t.taille-i-1);
	}
	return t;
}

TB aleadel(TB t){
	int i,j;
	j = alea(t.taille);
	for (i=j; i < t.taille; i++){
		t.tab[i] = t.tab[i + 1];
	}
	t.taille --;
	return t;
}

TB doublons(TB t){
	int TC,i,temp,p;
	for(TC = 0; TC < t.taille; TC++){
		for(p = TC + 1; p < t.taille; p++)
			if (t.tab[p] == t.tab[TC]){
				for (i=p; i < t.taille; i++)
					t.tab[i] = t.tab[i + 1];	
				t.taille--; p--;}
	}
	return t;	
	
}


TB triinsertion(TB t){ 
	int TC,i,temp,p;
	for(TC = 0; TC < t.taille - 1; TC++)
	{
		temp = t.tab[TC+1]; //voir TC+1
		p = 0;
		while(t.tab[p]<temp) p++;
		for(i=TC; i >= p; i--)
			t.tab[i+1] = t.tab[i];
		t.tab[p] = temp;
	}
	return t;
}


TB triselection(TB t){
	int i,m;
	for(i = 0; i < t.taille; i++)
		{m = mintab(t,i);
		t = swap(t,i,m);}	
	return t;
}

TB tribulles(TB t){ //permutation
	int TC,i,ech;
	for(TC = 1; TC <= t.taille - 1; TC++)
	{
		ech = t.taille; //**
		for(i = t.taille - 1; i >= TC; i--)
			if(t.tab[i- 1] > t.tab[i])
			{
				t = swap(t,i,i-1);
				ech = i;} //**
		TC = ech;} //** améliorations vues en IN303
	return t;
}

TB tridenomb(TB t, int m){ 
	TB u;
	int i,j;
	
	for(i = 0; i < m; i++)
		u.tab[i] = 0;
	for(i = 0; i < t.taille; i++)
		u.tab[t.tab[i]]++;
	
	i = j = 0;
	while(j < m)
	{
		if(u.tab[j] > 0)
		{
			t.tab[i] = j;
			u.tab[j]--;
			i++;
		}
		else j++;
	}	
	return t;
}

TB insertri(TB t, int e){
	int TC,i,k;
	if(t.taille == 0){
		t.taille = 1;
		t.tab[0] = e;}
		
	else {
		i = 0;
		while(i < t.taille && t.tab[i] < e) i++;
		if(i == t.taille && t.tab[i] < e) k = t.taille + 1;
		else k = i;
		for(i = t.taille; i >= k; i--)
			t.tab[i] = t.tab[i-1];
		t.tab[k] = e;
		t.taille ++;
	}
	
	return t;
}

int main(){
	
	int i = 0;
	srand(time(NULL));
	TB T = remplinit(T,10,20); //t.taille = 10 et les valeurs vont jusqu'à m = 20.
	
	printf("Tableau: ");
	affichtab(T);
	printf("Taille structure: %lu \n", sizeof(TB));
	printf("Produit: %ld \n", prodtab(T));
	printf("Somme: %ld \n", sommtab(T));
	printf("Minimum: %d \n", T.tab[mintab(T,0)]);
	printf("Maximum: %d \n", T.tab[maxtab(T,0)]);
	printf("Décalage du tableau vers la droite... \n");
	T = ins0gtab(T);
	affichtab(T);
	printf("Tri par permutation... \n");
	T = tribulles(T);
	affichtab(T);
	printf("Insertion de 12... \n");
	T = insertri(T,12);
	affichtab(T);
	printf("Inversion du tableau... \n");
	T = tinverse(T);
	affichtab(T);
	printf("Suppression aléatoire... \n");
	T = aleadel(T);
	affichtab(T);
	printf("Suppression doublons... \n");
	T = doublons(T);
	affichtab(T);
	printf("Tri par dénombrement... \n");
	T = tridenomb(T,20);
	affichtab(T);

  return 0;

}


