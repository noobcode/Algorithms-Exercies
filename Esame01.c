#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int key;
	struct nodo* sx;
	struct nodo* dx;
}nodo;
typedef nodo* albero;

typedef struct coppia{
	int somma;
	int min;
}coppia;

albero inserisci(albero t, int el){
	albero new = malloc(sizeof(nodo));
	new->key = el;
	new->sx = new->dx = NULL;

	if(t == NULL)
		t = new;
	else{
		if(t->key >= el)
			t->sx = inserisci(t->sx,el);
		else
			t->dx = inserisci(t->dx,el);
	}
	return t;	
}

int min(int a, int b){
	if(a <= b)	return a;
	else	return b;
}

int max(int a, int b){
	if(a >= b)	return a;
	else	return b;
}

coppia* cammino(albero t, coppia* x){
	if(t == NULL){
		x->somma = 0;
		x->min = 10000000;		
		return x;
	}else{
		coppia* c1 = malloc(sizeof(coppia));
		coppia* c2 = malloc(sizeof(coppia));
		c1 = cammino(t->sx, c1);
		c2 = cammino(t->dx, c2);
		//printf("c1 somma %d c2 somma %d\n",c1->somma, c2->somma);
		x->somma = max(c1->somma, c2->somma) + t->key;
		if(c1->somma >= c2->somma){
			x->min = min(t->key,c1->min);
			//printf("somma: %d min: %d\n", x->somma,x->min);
		}else{
			x->min = min(t->key,c2->min);
			//printf("somma: %d min: %d\n", x->somma,x->min);
		}return x;
	}
}

int main(){
	int i, n, el;
	albero t = NULL;
	coppia* x = malloc(sizeof(coppia));
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		t = inserisci(t,el);
	}
	if(t == NULL)
		printf("0\n");
	else{
		x = cammino(t,x);
		printf("%d\n",x->min);
	}	
	return 0;
}
