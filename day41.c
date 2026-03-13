#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return val;
}

int main() {
    int N;
    scanf("%d", &N);
    struct Queue q;
    initQueue(&q);
    
    for (int i = 0; i < N; i++) {
        char op[10];
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            int val;
            scanf("%d", &val);
            enqueue(&q, val);
        } else if (strcmp(op, "dequeue") == 0) {
            int res = dequeue(&q);
            if (res == -1) {
                printf("-1\n");
            } else {
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
