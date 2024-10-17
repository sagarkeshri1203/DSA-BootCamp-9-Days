#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Recursive function to print the linked list in reverse order
void printReverse(struct Node* head) {
    if (head == NULL) {
        return; // Base case: if the list is empty, return
    }
    printReverse(head->next); // Recursive call with the next node
    printf("%d ", head->data); // Print the data after the recursive call
}

// Function to add a node at the end of the linked list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Main function to demonstrate the functionality
int main() {
    struct Node* head = NULL;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Linked List in reverse order: ");
    printReverse(head); // Call the recursive function to print in reverse
    printf("\n");

    return 0;
}