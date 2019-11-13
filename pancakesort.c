#include <stdio.h>
#include<malloc.h>

void flip(int *a, int end_index){
    int bgng=0, temp;
    while(bgng<end_index){
        temp=*(a+end_index);
        *(a+end_index)=*(a+bgng);
        *(a+bgng)=temp;
        bgng++;
        end_index--;
    }
}

int MAX(const int *a, int end_index){
    int max=0, i;
    for(i=0; i<end_index; i++){
        if(*(a+i)>*(a+max))
            max=i;
    }
    return max;
}

void pancake(int *a, int n){
    int current_size=n;
    for(current_size=n; current_size>1; current_size--){
        int max=MAX(a, current_size);
        if(max!=current_size-1){
            flip(a, max);
            flip(a, current_size-1);
        }
    }

}


int main() {
    int *a, i, n;
    printf("\nenter the no.of elements in the array: ");
    scanf("%d", &n);
    a=(int*)malloc(n*sizeof(int));
    printf("\nenter the array: ");
    for(i=0; i<n; i++)
            scanf("%d", a+i);
    pancake(a, n);
    printf("\n");
    for(i=0; i<n; i++)
        printf("%d  ", *(a+i));
    return 0;
}