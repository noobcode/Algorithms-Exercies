#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

/* 
  !!!!!!!!!!!! D A  F A R E !!!!!!!!!!!!
  sx e dx sono le posizioni del primo e dell'ultimo elemento dell'array mentre 
  px è la posizione dell'elemento perno.
  La funzione deve restituire la posizione del perno dopo che gli elementi sono 
  stati partizionati.
*/
int distribuzione(int a[], int sx, int px, int dx) { 
	int temp,i,j;
	swap(&a[dx],&a[px]);
	i = sx-1;
	for(j = sx; j < dx; j++){
		if(a[j] < a[dx]){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[dx],&a[i+1]);
	return i+1;
}

int distribuzione2(int a[], int px, int dx) { 
	int temp,i,j;
	swap(&a[dx],&a[px]);
	i = px-1;
	for(j = px; j < dx; j++){
		if(a[j] == a[dx]){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[dx],&a[i+1]);
	return i+1;
}

void quicksort( int a[], int sx, int dx ) {
  
  int perno, pivot, perno2;
  if( sx < dx ) {
    /* DA IMPLEMENTARE: scelta del pivot. Scegliere una posizione a caso tra sx e dx inclusi. */
    pivot = rand() % (dx-sx+1) + sx;

    perno = distribuzione(a, sx, pivot, dx); /* separa gli elementi minori di a[pivot] 
					        da quelli maggiori o uguali */
	perno2 = distribuzione2(a,perno,dx);				        
    /* Ordina ricorsivamente le due metà */
    quicksort(a, sx, perno-1);
    quicksort(a, perno2+1, dx);
    
  }

}

/* Lettura di un array di interi da input. 
Il primo elemento è la lunghezza dell'array */
int legge(int **a, int *len) {

  int i;
  scanf("%d", len);
  if(*len <= 0) return 1;

  *a = (int *) malloc(*len * sizeof(int));
  if(*a == NULL) return 1;

  for( i = 0; i < *len; i++ ) 
	  scanf("%d", (*a)+i);
  
  return 0;

}

int main() {
  
  int i, n, *A;

  if( legge(&A, &n)) return 1;

  srand(time(NULL));
  quicksort(A, 0, n-1);
  
  /* Stampa l'array ordinato */
  for( i = 0; i < n; i++ ) 
    printf("%d ", A[i]);
	
  return 0;
}
