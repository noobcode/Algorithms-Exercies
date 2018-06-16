#include <stdio.h>
#include <stdlib.h>
// pari -> crescente
// dispari ->decrescente

void swap(int* a, int* b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

int compare_pari(const void *a, const void *b){
	int* A = (int*)a;
	int* B = (int*)b;
	return (*A - *B);
}

int compare_dispari(const void *a, const void *b){
	int* A = (int*)a;
	int* B = (int*)b;
	//if(*A % 2 == 1 && *B % 2 == 1) // se tolgo il controllo 
		return (*B - *A);
}

int partizione_pari_dispari(int *a, int sx, int dx){
	int i,j;
	i = sx-1;
	for(j = sx; j <= dx; j++){
		if(a[j] % 2 == 0){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	return i;
}

int main(){
	int *a,i,n,partizione;
	scanf("%d",&n);
	a = malloc(n * sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	partizione = partizione_pari_dispari(a,0,n-1);	
	qsort(a,partizione+1, sizeof(int), compare_pari);
	qsort(a+partizione+1, (n-1)-(partizione+1) + 1, sizeof(int), compare_dispari); // ! ! !	
	for(i = 0; i < n; i++)
		printf("%d\n",a[i]);
	return 0;
}
