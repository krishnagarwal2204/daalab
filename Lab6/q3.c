#include <stdio.h>
#include <stdlib.h>
int comparisons = 0, inversions = 0;
void merge(int A[], int B[], int C[], int p, int q) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        comparisons++;
        if (B[i] <= C[j]) {
            A[k++] = B[i++];
        } else {
            A[k++] = C[j++];
            inversions += (p - i);
        }
    }
    while (i < p) A[k++] = B[i++];
    while (j < q) A[k++] = C[j++];
}
void mergesort(int A[], int n) {
    if (n > 1) {
        int mid = n / 2;
        int *B = (int*)malloc(mid * sizeof(int));
        int *C = (int*)malloc((n - mid) * sizeof(int));
        for (int i = 0; i < mid; i++) B[i] = A[i];
        for (int i = mid; i < n; i++) C[i - mid] = A[i];
        mergesort(B, mid);
        mergesort(C, n - mid);
        merge(A, B, C, mid, n - mid);
        free(B);
        free(C);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int *A = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    mergesort(A, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\nNumber of comparisons: %d\n", comparisons);
    printf("Number of inversions: %d\n", inversions);
    free(A);
    return 0;
}
