#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = x;
}

// Dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Display
void display() {
    if (front == -1) {
        printf("Queue is empty");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}