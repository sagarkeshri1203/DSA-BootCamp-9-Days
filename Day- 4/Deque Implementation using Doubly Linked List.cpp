#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

int isEmpty(struct Deque* deque) {
    return deque->front == NULL;
}

void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = deque->front;
    newNode->prev = NULL;

    if (isEmpty(deque)) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }
    deque->front = newNode;
}

void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (isEmpty(deque)) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
}

int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque Underflow\n");
        return -1;
    }

    struct Node* temp = deque->front;
    int deletedData = temp->data;

    deque->front = deque->front->next;
    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL; // Deque is now empty
    }

    free(temp);
    return deletedData;
}

int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque Underflow\n");
        return -1;
    }

    struct Node* temp = deque->rear;
    int deletedData = temp->data;

    deque->rear = deque->rear->prev;
    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL; // Deque is now empty
    }

    free(temp);
    return deletedData;
}

int getFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->front->data;
}

int getRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->rear->data;
}

void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    struct Node* current = deque->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Deque* deque = createDeque();
    
    insertRear(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 5);
    
    printf("Deque elements: ");
    display(deque);
    
    printf("Front element: %d\n", getFront(deque));
    printf("Rear element: %d\n", getRear(deque));
    
    printf("Deleted from front: %d\n", deleteFront(deque));
    printf("Deleted from rear: %d\n", deleteRear(deque));
    
    printf("Deque elements after deletions: ");
    display(deque);
    
    return 0;
}