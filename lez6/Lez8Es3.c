#include <stdio.h>
#include <stdlib.h>

typedef struct Point{
	int x;
	int y;
}Point;

int compare(const void* p1, const void* p2){
	Point* P1 = (Point*) p1;
	Point* P2 = (Point*) p2;
	if((P1)->x < (P2)->x) return -1;
	if((P1)->x > (P2)->x) return 1;
	if((P1)->x == (P2)->x) return ((P2)->y - (P1)->y);

}


int main(){
	int n,i;
	Point* punti;
	scanf("%d",&n);
	punti = malloc(n * sizeof(Point));
	for(i = 0; i < n; i++){
		scanf("%d%d",&(punti[i].x), &(punti[i].y));
	}
	qsort(punti,n,sizeof(Point),compare);
	for(i = 0; i < n; i++){
		printf("%d %d\n",punti[i].x, punti[i].y);
	}
	
	
	return 0;
}
