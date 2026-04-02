#include <stdio.h>

#define MAX 100

struct Queue {
    int arr[MAX];
    int front, rear;
};

struct Stack {
    int arr[MAX];
    int top;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

void initStack(struct Stack *s) {
    s->top = -1;
}

void enqueue(struct Queue *q, int x) {
    q->arr[++q->rear] = x;
}

int dequeue(struct Queue *q) {
    return q->arr[q->front++];
}

int isQueueEmpty(struct Queue *q) {
    return q->front > q->rear;
}

void push(struct Stack *s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack *s) {
    return s->arr[s->top--];
}

int isStackEmpty(struct Stack *s) {
    return s->top == -1;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Queue q;
    struct Stack s;
    initQueue(&q);
    initStack(&s);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    while (!isQueueEmpty(&q)) {
        push(&s, dequeue(&q));
    }

    while (!isStackEmpty(&s)) {
        int x = pop(&s);
        printf("%d ", x);
        enqueue(&q, x);
    }

    return 0;
}