#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10  // Maximum number of vertices

// Adjacency Matrix Representation
void bfsMatrix(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = -1, rear = -1;

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS (Adjacency Matrix): ");
    while (front != rear) {
        start = queue[++front];
        printf("%d ", start);

        for (int i = 0; i < n; i++) {
            if (graph[start][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfsMatrix(int graph[MAX][MAX], int n, int start, int visited[MAX]) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[start][i] && !visited[i]) {
            dfsMatrix(graph, n, i, visited);
        }
    }
}

// Adjacency List Representation
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void bfsList(Node* adjList[], int n, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = -1, rear = -1;

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS (Adjacency List): ");
    while (front != rear) {
        start = queue[++front];
        printf("%d ", start);

        Node* temp = adjList[start];
        while (temp) {
            int v = temp->vertex;
            if (!visited[v]) {
                queue[++rear] = v;
                visited[v] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void dfsList(Node* adjList[], int start, int visited[MAX]) {
    printf("%d ", start);
    visited[start] = 1;

    Node* temp = adjList[start];
    while (temp) {
        int v = temp->vertex;
        if (!visited[v]) {
            dfsList(adjList, v, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n = 5;  // Number of vertices
    int adjMatrix[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    printf("Using Adjacency Matrix:\n");
    int visited[MAX] = {0};
    printf("DFS: ");
    dfsMatrix(adjMatrix, n, 0, visited);
    printf("\n");
    bfsMatrix(adjMatrix, n, 0);

    printf("\nUsing Adjacency List:\n");
    Node* adjList[MAX] = {NULL};

    // Add edges
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 2, 3);

    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS: ");
    dfsList(adjList, 0, visited);
    printf("\n");

    bfsList(adjList, n, 0);

    return 0;
}