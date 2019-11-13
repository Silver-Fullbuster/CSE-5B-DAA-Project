#include<stdio.h>
#include<stdlib.h>
#include <minmax.h>

#define MAX 1000
int min_run = 32;
int stack_base_index[MAX], TOP_base = -1, stack_size[MAX], TOP_size = -1;


void push_base_index(int *stack, int item) {
    if (TOP_base == MAX - 1) {
        printf("\nSTACK is FULL CAN't ADD ITEM\n");
        return;
    }
    TOP_base++;
    stack[TOP_base] = item;
}

int pop_base_index(int *stack) {
    int deletedItem;
    if (TOP_base == -1) {
        printf("STACK is EMPTY.\n");
        return -1;
    }

    deletedItem = stack[TOP_base];
    TOP_base--;
    return deletedItem;
}

void push_size(int stack[], int item) {
    if (TOP_size == MAX - 1) {
        printf("\nSTACK is FULL CAN't ADD ITEM\n");
        return;
    }
    TOP_size++;
    stack[TOP_size] = item;
}

int pop_size(int stack[]) {
    int deletedItem;
    if (TOP_size == -1) {
        printf("STACK is EMPTY.\n");
        return -1;
    }

    deletedItem = stack[TOP_size];
    TOP_size--;
    return deletedItem;
}

int binarySearch(int a[], int item, int low, int high) {
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;
    int mid = (low + high) / 2;
    if (item == a[mid])
        return mid + 1;
    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);
    return binarySearch(a, item, low, mid - 1);
}

void insertionSort(int a[], int m, int n) {
    int i, loc, j, k, selected;
    for (i = m + 1; i <= n; ++i) {
        j = i - 1;
        selected = a[i];
        loc = binarySearch(a, selected, m, j);
        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

void printArray(int *a, int n) {
    int i = 0;
    printf("\n*************\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void merge(int *a, int larger_bgng_index, int larger_end_index, int smaller_bgng_index, int smaller_end_index) {
//    printArray(a, 65);
    int smaller_size = smaller_end_index - smaller_bgng_index + 1;
    int *temp = (int *) malloc(smaller_size * sizeof(int));
    int i, j, k, flag_j = 1, flag_k = 1;
    for (i = 0; i < smaller_size; i++) {
        *(temp + i) = *(a + smaller_bgng_index + i);
    }
    if (smaller_bgng_index < larger_bgng_index) {
        i = smaller_bgng_index;
        j = 0, k = larger_bgng_index;
        while (j < smaller_size && k <= larger_end_index) {
            if (flag_j < 7 && flag_k < 7) {
                if (temp[j] <= a[k]) {
                    a[i++] = temp[j++];
                    flag_j++;
                    flag_k = 1;
                } else {
                    a[i++] = a[k++];
                    flag_k++;
                    flag_j = 1;
                }
            }
            if (flag_j == 7) { //checked
                int index = binarySearch(temp, a[k], j, smaller_end_index);
                while (j < index) {
                    a[i++] = temp[j++];
                }
//                printArray(a, 65);
                flag_j = 1;
                flag_k = 1;
            }
            if (flag_k == 7) {//checked
                int index = binarySearch(a, temp[j], k, larger_end_index);
                while (k < index) {
                    a[i++] = a[k++];
                }
                flag_j = 1;
                flag_k = 1;
            }
        }
        while (j < smaller_size)
            a[i++] = temp[j++];
        while (k <= larger_end_index)
            a[i++] = a[k++];

    } else {
        i = smaller_end_index;
        j = smaller_size - 1, k = larger_end_index;
        while (j >= 0 && k >= larger_bgng_index) {
            if (flag_j < 7 && flag_k < 7) {
                if (temp[j] >= a[k]) {
                    a[i--] = temp[j--];
                    flag_j++;
                    flag_k = 1;
                } else {
                    a[i--] = a[k--];
                    flag_k++;
                    flag_j = 1;
                }
            }
            if (flag_j == 7) { //checked
                int index = binarySearch(temp, a[k], j, smaller_end_index);
                while (j >= index) {
                    a[i--] = temp[j--];
                }
                flag_j = 1;
                flag_k = 1;
            }
            if (flag_k == 7) { //checked
                int index = binarySearch(a, temp[j], k, larger_end_index);
                while (k >= index) {
                    a[i--] = a[k--];
                }
                flag_j = 1;
                flag_k = 1;
            }
        }
        while (j >= 0)
            a[i--] = temp[j--];
        while (k >= larger_bgng_index)
            a[i--] = a[k--];
    }
//    printArray(a, 100);
}


void tim_sort(int *a, int n) {
    int i, current_run = -1, count = -1, bgng = 0, flag;
    if (n < 64)
        insertionSort(a, 0, n - 1);
    else {
        while (count < n - 1) {
            if (*(a + bgng) > *(a + bgng + 1))
                flag = 0;
            else
                flag = 1;
            if (flag == 0) {
                while (*(a + count) > *(a + count + 1) && count < n) {
                    current_run++;
                    count++;
                }
            } else {
                count++;
                current_run++;
                while (*(a + count) <= *(a + count + 1) && count < n - 1) {
                    current_run++;
                    count++;
                }
            }
            if (current_run < (min_run - 1)) {
                count = count + ((min_run - 1) - current_run);
                current_run = (min_run - 1);
            }
            if (count > n) {
                count = n - 1;
                current_run = count - bgng;
            }
            push_base_index(stack_base_index, bgng);
            push_size(stack_size, current_run);
            insertionSort(a, bgng, count);
            bgng = count + 1;
            current_run = -1;
        }
        while (TOP_size >= 2) {
            int x, y, z, x_b, y_b, z_b;
            x = pop_size(stack_size);
            y = pop_size(stack_size);
            z = pop_size(stack_size);
            x_b = pop_base_index(stack_base_index);
            y_b = pop_base_index(stack_base_index);
            z_b = pop_base_index(stack_base_index);
            if (x <= (y + z) || y <= z) {
                int min_a = min(x, z);
                if (min_a == x) {
                    push_size(stack_size, z);
                    push_base_index(stack_base_index, z_b);

                    push_base_index(stack_base_index, y_b);
                    push_size(stack_size, x + y + 1);
                    merge(a, y_b, y + y_b, x_b, x + x_b);
                } else {
                    push_base_index(stack_base_index, z_b);
                    push_size(stack_size, z + y + 1);
                    merge(a, y_b, y + y_b, z_b, z + z_b);
                    push_size(stack_size, x);
                    push_base_index(stack_base_index, x_b);
                }
            }
        }
        int x = pop_size(stack_size);
        int y = pop_size(stack_size);
        int x_b = pop_base_index(stack_base_index);
        int y_b = pop_base_index(stack_base_index);
        if (x < y)
            merge(a, y_b, y + y_b, x_b, x + x_b);
        else
            merge(a, x_b, x + x_b, y_b, y + y_b);
    }
}


int main() {
    setbuf(stdout, 0);
    int *a, n, i;
    printf("\nenter no.of elements in the array: ");
    scanf("%d", &n);
    a = (int *) malloc(n * sizeof(int));
    printf("\nenter the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", a + i);
    tim_sort(a, n);
    printf("\nsorted array: ");
    for (i = 0; i < n; i++)
        printf("%d  ", *(a + i));
    return 0;
}
