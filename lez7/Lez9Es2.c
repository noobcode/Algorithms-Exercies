#include<stdio.h>
#include<stdlib.h>

typedef struct Point{
	int x;
	int y;
	int c; 
}Point;

int compare(const void* a, const void* b){
	return *(int*)b - *(int*)a;
}

int interrogazione(Point* p, int n, int x1, int y1, int x2, int y2){
	int i, j,k = 0, count = 0, currentColor;
	int* colori; // array dei colori
	colori = malloc(n * sizeof(int)); // n punti => massimo n colori :)
	
	for(i = 0; i < n; i++){
		if((p+i)->x >= x1 && (p+i)->x <= x2  && (p+i)->y >= y1 && (p+i)->y <= y2){	// il punto appartiene all'area di interrogazione
			colori[k++] = (p+i)->c;
		}
	}
	qsort(colori, k, sizeof(int), compare);
			
	currentColor = -1;
	for(i = 0; i < k; i++){
		if(colori[i] != currentColor){
			count++;
			currentColor = colori[i];
		}
	}
	return count;		
}

int main(){
	int n, m, i;
	int x1,x2,y1,y2;  // x1 < x2 e y1 < y2
	int ris;
	Point* p;
	
	scanf("%d", &n); // n punti
	scanf("%d", &m); // m interrogazioni
	
	p = malloc(n * sizeof(Point));
	for(i = 0; i < n; i++){
		scanf("%d %d %d",&((p+i)->x), &((p+i)->y), &((p+i)->c));
	}
	
	for(i = 0; i < m; i++){
		scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
		ris = interrogazione(p, n, x1, y1, x2, y2);
		printf("%d\n",ris);
	}
	
	return 0;
}
