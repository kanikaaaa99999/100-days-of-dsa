#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;

    if(front == NULL) {
        front = rear = temp;
        rear->next = front;
    }
    else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

// Dequeue and move to rear (circular behavior)
void rotate() {
    if(front == NULL)
        return;

    front = front->next;
    rear = rear->next;
}

// Display queue
void display() {
    struct Node* temp = front;

    if(front == NULL)
        return;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        rotate();
    }

    display();

    return 0;
}