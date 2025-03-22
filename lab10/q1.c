#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n, i, j, k;
	printf("Enter the matrix size(Square matrix)\t");
	scanf("%d", &n);
	int matrix[n][n];
	printf("Enter the adjacency matrix elements\n");
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++)
			scanf("%d", &matrix[i][j]);
	}
	for(k = 0; k<n; k++){
		for(i = 0; i<n; i++){
			for(j = 0; j<n; j++)
				matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
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