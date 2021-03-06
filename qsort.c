#include <stdio.h>

#define MAXNUM 10
void quicksort(int[], int, int);
int data[MAXNUM];

int main(int argc, char** argv){
    int i;

    for(i = 0; i < MAXNUM; i++){
      printf("Please input data for sorting\n");
      scanf("%d", &data[i]);
    }

    quicksort(data, 0, MAXNUM-1);
    for(i = 0; i < MAXNUM; i++){
        printf("%d ", data[i]);
    }

    return 0;
}

void
quicksort(int a[], int l, int r){
    int v, i, j, t;
    int ii;
    if (r > l){
	v = a[r]; i = l - 1; j = r;
	for(;;){
	    while(a[++i] < v) ;
	    while(a[--j] > v);
	    if (i >= j) break;
	    t = a[i]; a[i] = a[j]; a[j] = t;

	}	
    t = a[i]; a[i] = a[r]; a[r] = t;
    
    for(ii = 0; ii < MAXNUM; ii++){
        printf("%d ", data[ii]);
    }
    printf("\n");
    
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
    }
}
