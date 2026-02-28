#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void createList(int n) {
    if (n <= 0) return;

    int i, data;
    struct Node *prev, *newNode;

   
    head = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    prev = head;

    
    for (i = 1; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        prev->next = newNode;
        prev = newNode;
    }

    
    prev->next = head;
}


void display() {
    if (head == NULL) {
        printf("\n");
        return;
    }

    struct Node *current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);         

    if (n > 0) {
        createList(n);        
    }
    display();               

    return 0;
}
