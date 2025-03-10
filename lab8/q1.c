#include <stdio.h>
int count=0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int heap[], int index) {
    int parent = index / 2; 
    while (index > 1 && heap[parent] < heap[index]) { 
        count++;
        swap(&heap[parent], &heap[index]);
        index = parent; 
        parent = index / 2;
    }
}
void insert(int heap[], int *size, int key) {
    (*size)++;  
    heap[*size] = key; 
    heapifyUp(heap, *size); 
}
int main() {
    int heap[100]; 
    int size = 0;
    int n,arr[100];
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter heap elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++) {
        insert(heap, &size, arr[i]);
    }
    printf("\nFinal Heap:\n");
    for(int i=1;i<=size;i++){
        printf("%d\t",heap[i]);
    }
    printf("\nOpcount:%d",count);
    return 0;
}
