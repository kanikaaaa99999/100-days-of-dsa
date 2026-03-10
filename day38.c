#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (rear == MAX - 1);
}

void push_front(int x) {
    if(front == 0){
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1){
        front = rear = 0;
    }
    else{
        front--;
    }

    deque[front] = x;
}

void push_back(int x) {
    if(isFull()){
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1){
        front = rear = 0;
    }
    else{
        rear++;
    }

    deque[rear] = x;
}

void pop_front() {
    if(isEmpty()){
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
}

void pop_back() {
    if(isEmpty()){
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if(front == rear){
        front = rear = -1;
    }
    else{
        rear--;
    }
}

void getFront() {
    if(isEmpty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void getBack() {
    if(isEmpty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

void getSize() {
    if(isEmpty())
        printf("Size: 0\n");
    else
        printf("Size: %d\n", rear - front + 1);
}

void display() {
    if(isEmpty()){
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for(int i = front; i <= rear; i++){
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);

    display();

    getFront();
    getBack();

    pop_front();
    pop_back();

    display();
    getSize();

    return 0;
}