#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = newNode;
}

void rotateRight(struct Node** head, int k) {
    if (*head == NULL || k == 0) return;
    
    struct Node* current = *head;
    int n = 1;
    while (current->next != NULL) {
        current = current->next;
        n++;
    }
    
    k = k % n;
    if (k == 0) return;
    
    current->next = *head;
    
    int steps = n - k;
    current = *head;
    for (int i = 1; i < steps; i++) {
        current = current->next;
    }
    
    *head = current->next;
    current->next = NULL;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

void freeList(struct Node** head) {
    struct Node* current = *head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        append(&head, data);
    }
    
    int k;
    scanf("%d", &k);
    
    rotateRight(&head, k);
    printList(head);
    
    freeList(&head);
    return 0;
}
