#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo* next;
}nodo;
typedef struct nodo* lista;
typedef lista* hashtable;

int h(int x, int a, int b, int n){
	return ((a*x +b) % 999149) % (2*n);
}

int inserisci(hashtable t, int x,int  pos){
	int trovato = 0;
	lista curr;
	lista new = malloc(sizeof(nodo));
	new->info = x;
	new->next = NULL;
	
	if(t[pos] == NULL){
		t[pos] = new;
		return 0; // no conflitto
	}else{
		curr = t[pos];
		while(!trovato && curr){
			if(new->info == curr->info)
				trovato = 1;
			curr = curr->next;	
		}
		if(trovato)
			return 0;
		else{	
			new->next = t[pos];
			t[pos] = new;
			return 1;	// conflitto++
		}	
	}
}

int maxlung(hashtable t, int n){
	int i, count = 0, lenmax = -1;
	lista curr;
	for(i = 0; i < 2*n; i++){
		curr = t[i];
		while(curr != NULL){
			count++;
			curr = curr->next;
		}
		if(count > lenmax)	lenmax = count;
		count = 0;
	}
	return lenmax;
}

int elementidistinti(hashtable t, int n){
	int i, count = 0;
	lista curr;
	for(i = 0; i < 2*n; i++){
		curr = t[i];
		while(curr != NULL){
			count++;
			curr = curr->next;
		}
	}
	return count;
}

int main(){
	int n, a, b, el, i, pos, conflitti = 0;
	hashtable t;
	lista curr;
	
	scanf("%d%d%d",&n,&a,&b);
	t = malloc(2*n * sizeof(nodo*));
	for(i = 0; i < 2*n; i++)	t[i] = NULL;
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		pos = h(el,a,b,n);
		conflitti += inserisci(t,el,pos);
	}
	printf("%d\n%d\n%d\n",conflitti,maxlung(t,n),elementidistinti(t,n));	
	return 0;
}
