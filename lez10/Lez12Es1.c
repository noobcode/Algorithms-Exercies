#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo* next;
}nodo;
typedef struct nodo* lista;
typedef struct nodo** table;

int h(int x, int a, int b, int n){
	return ((a*x +b) % 999149) % (2*n);
}
// se t[i] != NULL, conflitto++
// 
int inserisci(table t, int x,int  pos){
	lista new = malloc(sizeof(nodo));
	new->info = x;
	new->next = NULL;
	if(t[pos] == NULL){
		t[pos] = new;
		return 0; // no conflitto
	}else{
		new->next = t[pos];
		t[pos] = new;
		return 1;	// conflitto++
	}
}


int main(){
	int n, a, b, el, i, pos, conflitti = 0;
	int lenmax = -1, count = 0;
	table t;
	lista curr;
	
	scanf("%d%d%d",&n,&a,&b);
	t = malloc(2*n * sizeof(nodo*));
	for(i = 0; i < 2*n; i++)	t[i] = NULL;
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		pos = h(el,a,b,n);
		conflitti += inserisci(t,el,pos);
	}
	
	for(i = 0; i < 2*n; i++){
		curr = t[i];
		while(curr != NULL){
			count++;
			curr = curr->next;
		}
		if(count > lenmax)	lenmax = count;
		count = 0;
	}	
	printf("%d\n%d\n",lenmax,conflitti);
	return 0;	
}
