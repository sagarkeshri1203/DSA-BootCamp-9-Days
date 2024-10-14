#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void push(int value);
void pop();
void display();
int stack[SIZE];
int top = -1;   
int main() {
    int value, choice;

    while (1) {
        printf("\n*** MENU ***\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid selection! Try again.\n");
        }
    }
}
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack is full! Insertion not possible.\n");
    } else {
        stack[++top] = value; 
        printf("Insertion successful!\n");
    }
}
void pop() {
    if (top == -1) {
        printf("Stack is empty! Deletion not possible.\n");
    } else {
        printf("Deleted: %d\n", stack[top--]); 
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]); 
        }
    }
}