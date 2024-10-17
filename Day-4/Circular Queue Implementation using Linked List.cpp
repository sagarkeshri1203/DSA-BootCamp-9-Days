#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

struct CircularQueue* createQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(struct CircularQueue* queue) {
    return queue->front == NULL;
}

void enqueue(struct CircularQueue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
        queue->rear->next = queue->front; // Make it circular
    }
}

int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node* temp = queue->front;
    int dequeuedData = temp->data;

    if (queue->front == queue->rear) {
        // Only one element in the queue
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->rear->next = queue->front; // Maintain circularity
    }

    free(temp);
    return dequeuedData;
}

int peek(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* current = queue->front;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

int main() {
    struct CircularQueue* queue = createQueue();
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    
    printf("Circular Queue elements: ");
    display(queue);
    
    printf("Front element: %d\n", peek(queue));
    
    printf("Dequeued element: %d\n", dequeue(queue));
    
    printf("Circular Queue elements after dequeue: ");
    display(queue);
    
    return 0;
}