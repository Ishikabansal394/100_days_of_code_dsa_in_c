#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int stack[SIZE];
    int minStack[SIZE];
    int top;
    int minTop;
} MinStack;

void init(MinStack *s) {
    s->top = -1;
    s->minTop = -1;
}

void push(MinStack *s, int val) {
    s->stack[++(s->top)] = val;

    if(s->minTop == -1 || val <= s->minStack[s->minTop]) {
        s->minStack[++(s->minTop)] = val;
    }
}

void pop(MinStack *s) {
    if(s->top == -1) {
        printf("Stack empty\n");
        return;
    }

    int x = s->stack[s->top--];

    if(x == s->minStack[s->minTop]) {
        s->minTop--;
    }
}

int top(MinStack *s) {
    return s->stack[s->top];
}

int getMin(MinStack *s) {
    return s->minStack[s->minTop];
}

int main() {
    MinStack s;
    init(&s);

    push(&s, 5);
    push(&s, 3);
    push(&s, 7);
    push(&s, 2);

    printf("Top: %d\n", top(&s));      
    printf("Min: %d\n", getMin(&s));   

    pop(&s);

    printf("Top: %d\n", top(&s));      
    printf("Min: %d\n", getMin(&s));   

    return 0;
}