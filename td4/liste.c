#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct elem{
	int val;
	struct elem *suiv;	
	
};

int alea(int n)
{
	return rand()%n;		
}

typedef struct elem* liste;

liste creerlisteVide()
{
	return NULL;
}

int estlisteVide(liste l)
{
	return l == NULL;
}

void affiche_liste(liste l)
{
	while(!estlisteVide(l)){
	printf("(%d|%p)", l->val, l->suiv);
	l = l->suiv;}
	
}

void liberer_mem(liste l)
{
	if(!estlisteVide(l))
	{liberer_mem(l->suiv);
	free(l);}
	
}

liste inserer_tete(liste e, int n)
{
	liste a;
	a = malloc(sizeof(struct elem));
	if(a == NULL)  exit(1);
	a->val = n;
	a->suiv = e;
	return a;

}

liste inserer_fin(liste e, int n)
{
	liste a;
	if(e==NULL){
		a = malloc(sizeof(struct elem));
		if(a == NULL)  exit(1);
		a->val = n;
		a->suiv = NULL;
		return a;}
		
	e->suiv = inserer_fin(e->suiv,n);
	return e;
}

int est_trie(liste l){
	
	if(l->suiv == NULL) return 1;
	else if((l->suiv)->val <= (l->val)) return 0;
	return est_trie(l->suiv);	
	
}

liste inserer_trie(liste l, int n)
{
	liste a;
	
	//if (!est_trie(l)) return inserer_tete(l,n);
	
	if((l == NULL) || (n <= (l->val))){
		a = malloc(sizeof(struct elem));
		if(a == NULL)  exit(1);
		a->val = n;
		a->suiv = l;
		
		return a;	
	}
	
	l->suiv = inserer_trie(l->suiv,n);
	return l;
	
	
	
}

liste supprimer_tete(liste e)
{
	liste a;
	a = e;
	e = e->suiv;
	free(a);
	return e;

}

liste supprimer_fin(liste e)
{
	liste a;
	if(e==NULL) return NULL;
	if(e->suiv==NULL) {free(e); return NULL;} //ça semble être bon mais pour l'espace mémoire il faut tester avec valgrid...
		
	e->suiv = supprimer_fin(e->suiv);
	return e;
}

liste alea0(liste l, int n){
	
	int i;
	
	i = alea(n);
	l = inserer_tete(l,i);
	
	if(!i) return l;
	l = alea0(l,n);	
	
	return l;
	
}

int nbelem(liste l){
	if(l == NULL) return 0;
	return 1 + nbelem(l->suiv);	
	
}

liste tl(liste l) //ne supprime pas l'élément, voir supprimer_tete pour ça
{
	return l -> suiv;		
}

int main(){
	
	int i = 0;
	srand(time(NULL));
	liste l;
	l = creerlisteVide();
	l = alea0(l, 13);
	affiche_liste(l);
	printf("\n");
	if(est_trie(l))printf("\nTrié.\n");
	else printf("\nNon trié.\n");
	printf("\nInsertion de 6 (trié):\n");
	l=inserer_trie(l,6);
	affiche_liste(l);	
	printf("\n\nNombre d'éléments de la liste: ");
	printf("%d\n",nbelem(l));
	printf("\n-1 élément (fin):\n");
	l=supprimer_fin(l);
	affiche_liste(l);
	
	
	

  return 0;

}


