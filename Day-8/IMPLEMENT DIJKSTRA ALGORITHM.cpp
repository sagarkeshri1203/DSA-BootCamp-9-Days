#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight; // For undirected graph
}

void dijkstra(Graph* graph, int startVertex) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < graph->numVertices; i++) {
        distance[i] = graph->adjMatrix[startVertex][i];
    }
    distance[startVertex] = 0;
    visited[startVertex] = 1;

    for (int count = 0; count < graph->numVertices - 1; count++) {
        int minDistance = INT_MAX;
        int nextVertex;

        for (int i = 0; i < graph->numVertices; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                nextVertex = i;
            }
        }

        visited[nextVertex] = 1;

        for (int i = 0; i < graph->numVertices; i++) {
            if (!visited[i] && graph->adjMatrix[nextVertex][i] != INT_MAX) {
                int newDistance = distance[nextVertex] + graph->adjMatrix[nextVertex][i];
                if (newDistance < distance[i]) {
                    distance[i] = newDistance;
                }
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 0, 7);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 4, 3, 2);

    dijkstra(graph, 0);

    free(graph);
    return 0;
}