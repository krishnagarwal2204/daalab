#include<stdio.h>
#include<stdlib.h>
int minimum(int a, int b)
{
	if(a < b)
		return a;
	return b;
}
int main(void)
{
	int n, i, j, k;
	printf("Enter the matrix size(Square matrix)\t");
	scanf("%d", &n);
	int matrix[n][n];
	printf("Enter the weight matrix elements(enter 1000000 for infinity)\n");
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++)
			scanf("%d", &matrix[i][j]);
	}
	for(k = 0; k<n; k++){
		for(i = 0; i<n; i++){
			for(j = 0; j<n; j++)
				matrix[i][j] = minimum(matrix[i][j], (matrix[i][k] + matrix[k][j]));
		}
	}
	printf("The transitive closure is\n");
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++)
			printf("%d\t", matrix[i][j]);
		printf("\n");
	}
	return 0;
}