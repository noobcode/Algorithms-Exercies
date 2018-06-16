#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo* sx;
	struct nodo* dx;
}nodo;

typedef nodo* albero;
typedef struct coppia{
	int l;
	int r;
}coppia;

albero getNodo(int el){
	albero new = malloc(sizeof(nodo));
	new->info = el;
	new->sx = new->dx = NULL;
	return new;
}

albero inserisci(albero t, int el){
	if(t == NULL){	 
		albero new = getNodo(el);
		t = new;
		return t;
	}else if(t->info >= el)
		t->sx = inserisci(t->sx,el);
	else
		t->dx = inserisci(t->dx,el);
	return t;
}

coppia* visita(albero t, coppia* x,albero* t2){
	coppia* left, *right;
	if(t == NULL){
		x->l = -1;
		x->r = -1;
		return x;
	}
	left = malloc(sizeof(coppia));
	right = malloc(sizeof(coppia));
	left = visita(t->sx, left, t2);
	right = visita(t->dx,right,t2);
	
	x->l = left->l + 1;
	x->r = right->r + 1;
	if(x->l > x->r)
		*t2 = inserisci(*t2,t->info);
	return x;
}

void invisita(albero t){
	if(t != NULL){
		invisita(t->sx);
		printf("%d\n",t->info);
		invisita(t->dx);
	}

}

void cleantree(albero t){
	if(!t->sx && !t->dx){
		free(t);
		return;
	}
	else{
		cleantree(t->sx);
		cleantree(t->dx);
	}
}

int main(){
	int n, el, i;
	albero t = NULL;
	albero t2 = NULL;	
	coppia* x = malloc(sizeof(coppia));

	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		t = inserisci(t, el);
	}
	x = visita(t,x,&t2);
	invisita(t2);
	cleantree(t);
	cleantree(t2);
	return 0;
}

