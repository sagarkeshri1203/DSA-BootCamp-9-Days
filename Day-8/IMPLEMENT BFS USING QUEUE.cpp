#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(Queue* queue) {
    return queue->rear == MAX_VERTICES - 1;
}

int isEmpty(Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

void enqueue(Queue* queue, int value) {
    if (!isFull(queue)) {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->items[++queue->rear] = value;
    }
}

int dequeue(Queue* queue) {
    if (!isEmpty(queue)) {
        return queue->items[queue->front++];
    }
    return -1; // Queue is empty
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For undirected graph
}

void BFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    Queue* queue = createQueue();

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    free(queue);
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("BFS starting from vertex 0:\n");
    BFS(graph, 0);

    free(graph);
    return 0;
}