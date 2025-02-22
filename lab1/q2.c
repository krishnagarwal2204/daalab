#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
struct Node {
    int vertex;
    struct Node* next;
};
struct Graph {
    struct Node* adjList[MAX_VERTICES];
    int vertices;
};
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void initGraph(struct Graph* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
}
void addEdgeAdjList(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}
void displayAdjList(struct Graph* graph) {
    printf("Adjacency List Representation:\n");
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
void displayAdjMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Adjacency Matrix Representation:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}
void createAdjMatrix(struct Graph* graph, int adjMatrix[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* temp = graph->adjList[i];
        for (int j = 0; temp != NULL; j++) {
            adjMatrix[i][temp->vertex] = 1;
            temp = temp->next;
        }
    }
}
int main() {
    struct Graph graph;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    int vertices, edges, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&graph, vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdgeAdjList(&graph, src, dest);
    }
    displayAdjList(&graph);
    createAdjMatrix(&graph, adjMatrix);
    displayAdjMatrix(adjMatrix, vertices);
    return 0;
}