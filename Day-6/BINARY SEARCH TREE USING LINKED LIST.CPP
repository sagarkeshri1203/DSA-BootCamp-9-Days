#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int value);
struct Node* insert(struct Node* root, int value);
void inorder(struct Node* root);
void preorder(struct Node* root);
void postorder(struct Node* root);
struct Node* search(struct Node* root, int value);

int main() {
    struct Node* root = NULL;
    int choice, value;
    struct Node* result;

    while (1) {
        printf("\n\n*** BINARY SEARCH TREE MENU ***\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2: 
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = search(root, value);
                if (result != NULL) {
                    printf("\nValue %d found in the BST", value);
                } else {
                    printf("\nValue %d not found in the BST", value);
                }
                break;
            case 3: 
                printf("\nInorder traversal: ");
                inorder(root);
                break;
            case 4: 
                printf("\nPreorder traversal: ");
                preorder(root);
                break;
            case 5: 
                printf("\nPostorder traversal: ");
                postorder(root);
                break;
            case 6: 
                exit(0);
            default: 
                printf("\nInvalid choice! Try again.");
        }
    }
}

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function for inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function for preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}