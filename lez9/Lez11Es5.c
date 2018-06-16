#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo* left;
	struct nodo* center;
	struct nodo* right;
}nodo;
typedef nodo* albero;

albero inserisci(albero t, int el){
	if(t == NULL){
		albero new = malloc(sizeof(nodo));
		new->info = el;
		new->left = NULL;
		new->center = NULL;
		new->right = NULL;
		return new;
	}
	if(t->info > el)	
		t->left = inserisci(t->left,el);
	else if(el % t->info == 0)	
		t->center = inserisci(t->center,el);
	else	
		t->right = inserisci(t->right,el);
	return t;
}

int conta(albero t){
	if(t == NULL)	
		return 0;	
	if(t->left && t->center && t->right)
		return 1 + conta(t->left) + conta(t->center) + conta(t->right);
	else
		return conta(t->left) + conta(t->center) + conta(t->right);
}

int main(){
	int n, i, el;
	albero t = NULL;
	
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		t = inserisci(t,el);
	}
	printf("%d\n",conta(t));
	return 0;
}
