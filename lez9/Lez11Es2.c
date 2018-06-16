#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo* left;
	struct nodo* right;
}nodo;  
typedef nodo* albero;

albero inserisci(albero t, int el){
	if(t == NULL){
		albero new = malloc(sizeof(nodo));
		new->info = el;
		new->left = NULL;
		new->right = NULL;
		return new;
	}
	if(el < t->info)
		t->left = inserisci(t->left, el);
	else
		t->right = inserisci(t->right, el);
	return t;
}

int max(int a, int b){
	if(a>=b) return a;
	else return b;
}

void in_order_visit(albero t){
	if(t != NULL){
		in_order_visit(t->left);
		printf("%d\n",t->info);
		in_order_visit(t->right);
	}
}

int altezza(albero t){
	if(t == NULL)	return 0;
	else{
		int altsx, altdx,alt;
		altsx = altezza(t->left);
		altdx = altezza(t->right);
		return (max(altsx,altdx) + 1);
	}
}

int main(){

	int n, i,el, depth;
	albero t = NULL;

	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		t = inserisci(t,el);
	}
	//in_order_visit(t);
	printf("%d\n",altezza(t));
	
	return 0;
}
	
