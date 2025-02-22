#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
void bfs(int sv,int n){
    int queue[MAX];
    int f=-1,r=-1;
    queue[++r]=sv;
    visited[sv]=1;
    while(f!=r){
        f++;
        int cv=queue[f];
        printf("Visted: %d\n",cv);
        for(int i=0;i<n;i++){
            if(graph[cv][i]==1 && !visited[i]){
                queue[++r]=i;
                visited[i]=1;
            }
        }
    }
}
int main(){
    int n;
    printf("Enter number of vertices.\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    bfs(0,n);
    return 0;
}
