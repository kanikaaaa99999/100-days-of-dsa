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

void append(struct Node** head_ref, int data) {
    struct Node* new_node = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void deleteFirstOccurrence(struct Node** head_ref, int key) {
    if (*head_ref == NULL) return;
    
    struct Node* temp = *head_ref;
    if (temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    
    if (temp->next != NULL) {
        struct Node* to_delete = temp->next;
        temp->next = to_delete->next;
        free(to_delete);
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    int first = 1;
    while (temp != NULL) {
        if (!first) printf(" ");
        printf("%d", temp->data);
        first = 0;
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        append(&head, x);
    }
    
    int key;
    scanf("%d", &key);
    
    deleteFirstOccurrence(&head, key);
    printList(head);
    
    freeList(&head);
    return 0;
}
