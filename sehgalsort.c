#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define n 324

int main() {
    int arr[n] = {1, 0, 5, 9, 3, 7, 1, 0, 5, 9, 3, 7, 1, 0, 5, 9, 3, 7, 1, 0};
    int arr2[n], arr3[n];
    memcpy(arr2,arr,sizeof(int)*n);
    int k, i, j = 0;
    for(k = 0; k < sizeof(int)*8 ; k++) {
        for (i = 0; i < n; i++) {
            arr[i] = arr[i] >> 1;
            if (!arr[i]) {
                arr3[j++] = arr2[i];
                arr[i] = -1;
            }
        }
    }
    int key;
    j=0;
    for(i=1;i<n;i++){ 
        key = arr3[i]; 
        j = i - 1; 
        while(j >= 0 && arr3[j] > key){ 
            arr3[j+1] = arr3[j]; 
            j = j - 1; 
        } 
        arr3[j+1] = key; 
    } 

    for(i = 0; i < n; i++)
       printf("%d ", arr3[i]);
    return 0;
}
