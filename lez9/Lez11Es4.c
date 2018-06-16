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
	if(t->info > el)	t->left = inserisci(t->left,el);
	else	t->right = inserisci(t->right,el);
	return t;
}

int max(int a, int b){
	if(a>=b)	return a;
	else	return b;
}

int altezza(albero t){
	if(t == NULL)	return 0;
	int altsx, altdx;
	altsx = altezza(t->left);
	altdx = altezza(t->right);
	return max(altsx,altdx) + 1;
}

void cerca(albero t, int k, int* seqt, int* i){
	if(k == t->info)	return;
	else{
		seqt[*i] = t->info;
		*i = *i +1;
		if(t->info >= k)	cerca(t->left,k,seqt,i);
		else	cerca(t->right,k,seqt,i);
	}
}

int confronta_alberi(albero t1, albero t2, int k){
	int* seqt1,*seqt2;
	int i = 0, j = 0, uguali = 1;
	int z;
	seqt1 = calloc(altezza(t1),sizeof(int));
	seqt2 = calloc(altezza(t2),sizeof(int));
	
	cerca(t1,k,seqt1,&i);
	cerca(t2,k,seqt2,&j);
	
	if(i != j)	
		return 0;
	else{	
		z = 0;	
		while(uguali && z < i){
			if(seqt1[z] != seqt2[z])
				uguali = 0;
			z++;	
		}
		return uguali;
	}
}


int main(){
	int n,i,el,k;
	albero t1 = NULL,t2 = NULL;
	scanf("%d%d",&n,&k);
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		t1 = inserisci(t1,el);
	}
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		t2 = inserisci(t2,el);
	}
	printf("%d\n",confronta_alberi(t1,t2,k));	
	return 0;
}
