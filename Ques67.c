#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

// push
void push(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

// pop
int pop() {
    if(top == NULL) {
        printf("Stack empty\n");
        return -1;
    }
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char exp[100];
    printf("enter postfix: ");
    scanf(" %[^\n]", exp);   // read full line

    int i = 0;

    while(exp[i] != '\0') {

        // skip spaces
        if(exp[i] == ' ') {
            i++;
            continue;
        }

        // if digit
        if(isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        // operator
        else {
            int b = pop();
            int a = pop();

            if(exp[i] == '+') push(a + b);
            else if(exp[i] == '-') push(a - b);
            else if(exp[i] == '*') push(a * b);
            else if(exp[i] == '/') push(a / b);
        }

        i++;
    }

    printf("result: %d", pop());

    return 0;
}