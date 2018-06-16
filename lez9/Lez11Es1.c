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

int ricerca(albero t, int el){
	if(t == NULL)	return -1;
	if(t->info == el)	return 0;
	int depth = -1;
	if(t->info < el)
		depth = ricerca(t->right,el);
	else
		depth = ricerca(t->left,el);

	if(depth >= 0)	return depth + 1;
	else return -1;
}

int main(){

	int n, i,el, depth;
	albero t = NULL;

	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		t = inserisci(t,el);
	}
	
	scanf("%d",&el);
	while(el >= 0){
		depth = ricerca(t,el);
		if(depth >= 0)	printf("%d\n",depth);
		else	printf("NO\n");
		scanf("%d",&el);
	}	
	return 0;
}
	
