#include <stdio.h>

#define kNumLeonardoNumbers 44
#define inputSize 13
#define treeSizes 8 //1 + log(inputSize)

int size[treeSizes], sizeN = 0;

const int kLeonardoNumbers[kNumLeonardoNumbers] = {
        1u, 1u, 3u, 5u, 9u, 15u, 25u, 41u, 67u, 109u, 177u, 287u, 465u, 753u,
        1219u, 1973u, 3193u, 5167u, 8361u, 13529u, 21891u, 35421u, 57313u, 92735u,
        150049u, 242785u, 392835u, 635621u, 1028457u, 1664079u, 2692537u,
        4356617u, 7049155u, 11405773u, 18454929u, 29860703u, 48315633u, 78176337u,
        126491971u, 204668309u, 331160281u, 535828591u, 866988873u, 1402817465u,
};

void heapify(int arr[], int root, int start, int order) {
    if(order > 1) {
        int left = start + kLeonardoNumbers[order - 1] - 1, right = root - 1, largest = root, temp;
        if (arr[root] < arr[left])
            largest = left;
        if (arr[largest] < arr[right])
            largest = right;
        if (largest == left) {
            temp = arr[largest];
            arr[largest] = arr[root];
            arr[root] = temp;
            heapify(arr, left, start, order - 1);
        } else if (largest == right) {
            temp = arr[largest];
            arr[largest] = arr[root];
            arr[root] = temp;
            heapify(arr, right, start + kLeonardoNumbers[order - 1], order - 2);
        }
    }
}

void startHeapify(int *arr, const int i) {
    int start = 0, loopI;
    for (loopI = 0;
         loopI < sizeN && (start + kLeonardoNumbers[size[loopI]] - 1) != i; start += kLeonardoNumbers[size[loopI++]]);
    heapify(arr, i, start, size[loopI]);
}

void balanceHeap(int arr[], int i, int sizeN) {
    if (sizeN < 2 && size[sizeN - 1] < 2) // only singleton
        return;
    int sizeI = sizeN - 1, next = i, root = next - kLeonardoNumbers[size[sizeI]];
    while (size[sizeI] < 2 && root >= 0) { // singleton at end
        if (arr[root] > arr[next]) {
            int temp = arr[root];
            arr[root] = arr[next];
            arr[next] = temp;
            next = root;
            root -= kLeonardoNumbers[size[--sizeI]];
        } else return;
    }
    while (root >= 0) { // no singletons
        if (arr[root] > arr[next] && arr[root] > arr[next - 1] &&
            arr[root] > arr[root + kLeonardoNumbers[size[sizeI] - 1]]) {
            int temp = arr[root];
            arr[root] = arr[next];
            arr[next] = temp;
            next = root;
            root -= size[--sizeI];
        } else break;
    }
    startHeapify(arr, next);
}

void addToHeap(int arr[], int i) {
    if (sizeN == 0) {
        size[sizeN++] = 1;
    } else if (sizeN > 1 && size[sizeN - 1] + 1 == size[sizeN - 2]) {
        size[--sizeN - 1]++;
    } else if (size[sizeN - 1] == 1) {
        size[sizeN++] = 0;
    } else {
        size[sizeN++] = 1;
    }
    balanceHeap(arr, i, sizeN);
}

void makeLeonardoHeap(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        addToHeap(arr, i);
}

void removeFromHeap(int arr[], int *n) {
    (*n)--;
    if (size[sizeN - 1] > 1) {
        size[sizeN] = size[sizeN - 1] - 2;
        size[sizeN++ - 1]--;
        if (size[sizeN - 2] == 1)
            balanceHeap(arr, (*n) - 2, sizeN - 1);
        balanceHeap(arr, (*n) - 1, sizeN);
    } else {
        sizeN--;
    }
}

void smoothSort(int arr[], int n) {
    makeLeonardoHeap(arr, n);
    while (n > 1) {
        removeFromHeap(arr, &n);
    }
}

int main() {
    int arr[inputSize] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    smoothSort(arr, inputSize);
    int i;
    for (i = 0; i < inputSize; i++)
        printf("%d ", arr[i]);
    return 0;
}