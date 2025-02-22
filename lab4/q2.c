#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int pushorder[MAX];
int poporder[MAX];
int pushindex=0,popindex=0;
void dfs(int v,int n){
    visited[v]=1;
    pushorder[pushindex++]=v;
    for(int i=0;i<n;i++){
        if(graph[v][i]==1 && !visited[i]){
            dfs(i,n);
        }
    }
    poporder[popindex++]=v;
}
int main(){
    int n,edges;
    printf("Enter number of vertices.\n");
    scanf("%d",&n);
    printf("Enter number of edges.\n");
    scanf("%d",&edges);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
        visited[i]=0;
    }
    printf("Enter the edges:\n");
    for(int i=0;i<edges;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u][v]=1;
            graph[v][u]=1;
    }
    printf("Starting from vertex 0:\n");
    dfs(0,n);
    printf("Push order:\n");
    for(int i=0;i<pushindex;i++){
        printf("%d\t",pushorder[i]);
    }
    printf("\nPop order:\n");
    for(int i=0;i<popindex;i++){
        printf("%d\t",poporder[i]);
    }
    return 0;
}