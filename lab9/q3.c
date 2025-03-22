#include <stdio.h>
#include <stdlib.h>
int count=0;
void createhash(int hash[100],int key,int capacity,int visited[]){
	int hashindex=key%capacity;
	if(visited[hashindex]==0){
		hash[hashindex]=key;
		visited[hashindex]=1;
	}
	else{
		int i=hashindex;
		do{
			i++;
			i%=capacity;
			if(visited[i]==0){
				hash[i]=key;
				visited[i]=1;
				break;
			}
		}while(i!=hashindex);
	}
}
int search(int hash[100],int key,int capacity,int visited[]){
	int hashindex=key%capacity;
	if(visited[hashindex]==1){
	count++;
	if(hash[hashindex]==key){
		return hashindex;
	}
	else{
		int i=hashindex;
		do{
			i++;
			i%=capacity;
			if(visited[i]==0){
				return -1;
			}
			else if(hash[i]==key & count++){
				return i;
			}
		}while(i!=hashindex);
	}
}
else{
	return -1;
}
}
int main(){
	int m,n;
	int hash[100],keys[100];
	int key;
	int visited[100];
	printf("Enter hash capacity.\n");
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		visited[i]=0;
	printf("Enter number of keys\n");
	scanf("%d",&n);
	if(m<n){
		printf("Closed hashing not possible\n");
		return 0;
	}
	printf("Enter keys\n");
	for(int i=0;i<n;i++){
		scanf("%d",&key);
		createhash(hash,key,m,visited);
	}
	printf("Enter key to be searched\n");
	scanf("%d",&key);
	if(search(hash,key,m,visited)!=-1){
		printf("Search successful\n");
		printf("%d found at %d position in hash table\n",key,search(hash,key,m,visited));
		printf("Number of searches:%d",count);
	}
	else{
		printf("Search unsuccessful\n");
		printf("%d not found in hash table\n",key);
		printf("Number of searches:%d",count);
	}
	return 0;
}
