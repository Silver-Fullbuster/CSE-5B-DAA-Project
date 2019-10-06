#include <stdio.h>

int main() {
    int arr[] = {3,5,4,1,2};
    int n = 5, i, temp;
    for(i = 1; i < n;){
        if(i != 0 && arr[i] < arr[i-1]) {
            temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
            i--;
        } else i++;
    }
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}