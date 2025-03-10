#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void buildHeap(int H[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        int k = i, v = H[k], heap = 0;
        while (!heap && 2 * k <= n) {
            int j = 2 * k;
            if (j < n && H[j] < H[j + 1]) j++; 
            if (v >= H[j])
                heap = 1;
            else {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}
void heapifyDown(int H[], int n, int i) {
    int k = i, v = H[k], heap = 0;
    while (!heap && 2 * k <= n) {
        int j = 2 * k;
        if (j < n && H[j] < H[j + 1]) j++; 
        if (v >= H[j])
            heap = 1;
        else {
            H[k] = H[j];
            k = j;
        }
    }
    H[k] = v;
}
void heapSort(int H[], int n) {
    buildHeap(H, n); 
    for (int i = n; i > 1; i--) {
        swap(&H[1], &H[i]); 
        heapifyDown(H, i - 1, 1); 
    }
}
int main() {
    int n,arr[100];
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter heap elements\n");
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Original Array:\n");
    for(int i=1;i<=n;i++){
        printf("%d\t",arr[i]);
    }   
    heapSort(arr,n);
    printf("\nSorted Array:\n");
    for(int i=1;i<=n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
