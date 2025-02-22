#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int opcount=0;
void swap(int * a,int *b){
	int temp= *a;
	*a=*b;
	*b=temp;
}
int partition(int * arr,int l,int r){
	int p=arr[l];
	int i=l;
	int j=r+1;
	while(1){
		while(1){
			i++;
			opcount++;
			if(arr[i]>=p)
				break;
		}
		while(1){
			j--;
			opcount++;
			if(arr[j]<=p)
				break;
		}
		swap(&arr[i],&arr[j]);

		if(i>=j)
			break;
	}
	swap(&arr[i],&arr[j]);
	swap(&arr[l],&arr[j]);
	return j;
}
void kqsort(int * arr,int l,int r){
	if(l<r){
		int s=partition(arr,l,r);
		kqsort(arr,l,s-1);
		kqsort(arr,s+1,r);
	}
}
int main(){
	int arr[100],n;
	printf("Enter the number of integers you want to sort\n");
	scanf("%d",&n);
	printf("Enter the integers you want to sort one by one\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Original array\n");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}	
	kqsort(arr,0,n-1);
	printf("\nSorted array\n");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
    printf("\nOpcount: %d",opcount);
	return 0;
}