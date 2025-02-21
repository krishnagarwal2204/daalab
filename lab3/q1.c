#include<stdio.h>
int compcount=0;
int swapcount=0;
void sort(int * arr,int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            compcount++;
            if(arr[j+1]<arr[j]){
                swapcount++;
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main(){
    int arr[100],n;
    printf("Enter number of integers you want to sort\n");
    scanf("%d",&n);
    printf("Enter the integers to sort one by one\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Sorted array:\n");
    sort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\nSwaps: %d",swapcount);
    printf("\nComparisons: %d",compcount);
    return 0;
}