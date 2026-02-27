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

void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int findFirstIntersection(struct Node* head1, struct Node* head2) {
    struct Node* curr1 = head1;
    while (curr1 != NULL) {
        struct Node* curr2 = head2;
        while (curr2 != NULL) {
            if (curr1->data == curr2->data) {
                return curr1->data;
            }
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
    return -1;
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    
    struct Node* head1 = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        appendNode(&head1, val);
    }
    
    scanf("%d", &m);
    
    struct Node* head2 = NULL;
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        appendNode(&head2, val);
    }
    
    int intersection = findFirstIntersection(head1, head2);
    if (intersection != -1) {
        printf("%d\n", intersection);
    } else {
        printf("No Intersection\n");
    }
    
    freeList(head1);
    freeList(head2);
    
    return 0;
}
