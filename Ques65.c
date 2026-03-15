#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int k = 0;

    printf("enter infix: ");
    scanf("%s", infix);

    for(int i = 0; infix[i] != '\0'; i++) {

        // operand
        if(isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }

        // operator
        else {
            while(top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    // pop remaining
    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("postfix: %s", postfix);

    return 0;
}