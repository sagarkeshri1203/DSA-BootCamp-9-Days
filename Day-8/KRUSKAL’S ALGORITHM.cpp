#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int numVertices, numEdges;
    Edge edges[MAX];
} Graph;

int parent[MAX];

int find(int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent[i]);
}

void unionSets(int u, int v) {
    parent[u] = v;
}

int compare(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskal(Graph* graph) {
    int mstWeight = 0;
    int edgesIncluded = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        parent[i] = -1;
    }

    qsort(graph->edges, graph->numEdges, sizeof(graph->edges[0]), compare);

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < graph->numEdges; i++) {
        int u = find(graph->edges[i].src);
        int v = find(graph->edges[i].dest);

        if (u != v) {
            printf("%d -- %d == %d\n", graph->edges[i].src, graph->edges[i].dest, graph->edges[i].weight);
            unionSets(u, v);
            mstWeight += graph->edges[i].weight;
            edgesIncluded++;
        }

        if (edgesIncluded == graph->numVertices - 1) {
            break;
        }
    }

    printf("Total weight of Minimum Spanning Tree: %d\n", mstWeight);
}

int main() {
    Graph graph;
    printf("Enter number of vertices: ");
    scanf("%d", &graph.numVertices);
    printf("Enter number of edges: ");
    scanf("%d", &graph.numEdges);

    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < graph.numEdges; i++) {
        scanf("%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, &graph.edges[i].weight);
    }

    kruskal(&graph);

    return 0;
}