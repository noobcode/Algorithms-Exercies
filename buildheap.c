#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo* left;
	struct nodo* right;
} nodo_t;

typedef nodo_t* tree;


tree creaNodo(int x, tree left, tree right){
	tree new = malloc(sizeof(nodo_t));
	new->info = x;
	new->left = left;
	new->right = right; 
	return new;
}

tree creaTree(int a[], int i, int dim){
	if(i >= dim)
		return NULL;
	else{
		return creaNodo(a[i], creaTree(a, (i*2)+1, dim), creaTree(a, (i*2)+2, dim));
	}
}

void stampaTree(tree t){
	if(t != NULL){
		stampaTree(t->left);
		printf("%d ", t->info);
		stampaTree(t->right);
	}
}

int main(){
	int n = 5;
	int a[] = {1,2,3,4,5};
	tree t = creaTree(a, 0, n);
	stampaTree(t);
}
