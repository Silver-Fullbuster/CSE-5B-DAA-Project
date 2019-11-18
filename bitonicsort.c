#include <stdio.h>
#include <stdlib.h>
#define n 8

int up = 1, down = 0, a[n] = {9,8,7,6,1,2,4,3};

void bitonic_compare(int i, int j, int dir){
    int temp;
    if (dir == (a[i] > a[j])){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void bitonic_merge(int low, int high, int dir){
    int mid, i;
    if (high > 1){
        mid = high / 2;
        for (i = low; i < (low + mid); i++)
            bitonic_compare(i, i + mid, dir);    
        bitonic_merge(low, mid, dir);
        bitonic_merge(low + mid, mid, dir);    
    }
}

void bitonic_sort(int low, int high, int dir){
    int mid;
    if (high > 1){
        mid = high / 2;
        bitonic_sort(low, mid, up);
        bitonic_sort(low + mid, mid, down);
        bitonic_merge(low, high, dir);
    }
}

int main(){
	int i;
	bitonic_sort(0,n,up);
	printf("Sorted array:\n");
	for(i=0; i<n; i++)
		printf("%d",a[i]);
	return 0;
}
