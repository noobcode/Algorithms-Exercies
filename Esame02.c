#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct nodo{
	int key;
	int color;
	struct nodo* sx;
	struct nodo* dx;
}nodo;
typedef nodo* albero;

typedef struct coppia{
	int bil;
	int alt;
}coppia;

albero inserisci(albero t, int el , int color){
	if(t == NULL){
		albero new = malloc(sizeof(nodo));
		new->key = el;
		new->color = color;
		new->sx = new->dx = NULL;
		t = new;
		return t;
	}else if(t->key < el)
		t->dx = inserisci(t->dx,el, color);
	else
		t->sx = inserisci(t->sx,el, color);
	return t;
}

int max(int a, int b){
	if(a>=b)	return a;
	else	return b;
}

coppia* altrossa(albero t, coppia *x){
	coppia* c1,*c2;	
	if(t == NULL){
		x->bil = 1;
		x->alt = 0;
		return x;
	}else{
		c1 = malloc(sizeof(coppia));
		c2 = malloc(sizeof(coppia));
		c1 = altrossa(t->sx, c1);
		c2 = altrossa(t->dx, c2);
		
		if(c1->bil && c2-> bil && abs(c1->alt - c2->alt) <= 1)
			x->bil = 1;
		else
			x->bil = 0;

		x->alt = max(c1->alt,c2->alt);
		if(t->color == 0)
			x->alt++;
		return x;
	}
		
}

int main(){
	int i,n,el,color;
	albero t = NULL;
	coppia* c = malloc(sizeof(coppia));

	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d%d", &el, &color);
		t = inserisci(t,el,color);
	}
	c = altrossa(t, c);
	if(c->bil)
		printf("TRUE\n");
	else
		printf("FALSE\n");
	return 0;
}
