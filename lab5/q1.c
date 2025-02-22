#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int poporder[MAX];
int removalorder[MAX];
int removalindex=0,popindex=0;
void dfs(int v,int n){
    visited[v]=1;
    for(int i=0;i<n;i++){
        if(graph[v][i]==1 && !visited[i]){
            dfs(i,n);
        }
    }
    poporder[popindex++]=v;
}
void sourceremoval(int n){
    
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
    }
    int ch;
    printf("Enter 1 for dfs and 2 for source removal.\n");
    scanf("%d",&ch);
    switch(ch){
        case 1: for(int i=0;i<n;i++){
            if(!visited[i])
                dfs(i,n);
            }
            printf("Topological sort:\n");
            for(int i=n-1;i>=0;i--)
                printf("%d\t",poporder[i]);
            break;
        case 2:
    }
    return 0;
}