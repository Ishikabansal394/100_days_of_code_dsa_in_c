#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n;
    printf("enter number of tokens: ");
    scanf("%d", &n);

    char tokens[100][20];

    printf("enter tokens: ");
    for(int i = 0; i < n; i++) {
        scanf("%s", tokens[i]);
    }

    for(int i = 0; i < n; i++) {

        // if operator
        if(strcmp(tokens[i], "+") == 0 ||
           strcmp(tokens[i], "-") == 0 ||
           strcmp(tokens[i], "*") == 0 ||
           strcmp(tokens[i], "/") == 0) {

            int b = pop();
            int a = pop();

            if(strcmp(tokens[i], "+") == 0) push(a + b);
            else if(strcmp(tokens[i], "-") == 0) push(a - b);
            else if(strcmp(tokens[i], "*") == 0) push(a * b);
            else if(strcmp(tokens[i], "/") == 0) push(a / b);
        }

        else {
            push(atoi(tokens[i]));
        }
    }

    printf("result: %d", pop());

    return 0;
}