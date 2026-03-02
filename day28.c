#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);
    
    struct Node* head = NULL;
    
    if (n > 0) {
        // Read first node
        int data;
        scanf("%d", &data);
        head = (struct Node*)malloc(sizeof(struct Node));
        head->data = data;
        head->next = head;  // Point to itself initially
        
        struct Node* tail = head;
        
        // Read remaining nodes
        for (int i = 1; i < n; i++) {
            scanf("%d", &data);
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Traverse and print (one full cycle starting from head)
    if (head != NULL) {
        struct Node* current = head;
        int first = 1;
        do {
            if (!first) printf(" ");
            printf("%d", current->data);
            first = 0;
            current = current->next;
        } while (current != head);
        printf("\n");
        
        // Free memory
        struct Node* current = head;
        do {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        } while (current != head);
    }
    
    return 0;
}
