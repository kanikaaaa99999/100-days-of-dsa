#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue
struct Node* queue[1000];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    front = rear = 0;
    enqueue(root);

    int i = 1;

    while (!isEmpty() && i < n) {
        struct Node* curr = dequeue();

        // Left child
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Right view function
void rightView(struct Node* root) {
    if (!root) return;

    front = rear = 0;
    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* temp = dequeue();

            // If last node of level → print
            if (i == size - 1) {
                printf("%d ", temp->data);
            }

            if (temp->left) enqueue(temp->left);
            if (temp->right) enqueue(temp->right);
        }
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}