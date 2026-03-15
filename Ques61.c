#include <stdio.h>

int main() {
    int n;

    printf("enter number of operations: ");
    scanf("%d", &n);

    int stack[100];
    int top = -1;

    for(int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);

        if(op == 1) {
            int x;
            scanf("%d", &x);

            if(top == 99) {
                printf("Stack Overflow\n");
            } else {
                top++;
                stack[top] = x;
            }
        }

        else if(op == 2) {
            if(top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top]);
                top--;
            }
        }

        else if(op == 3) {
            if(top == -1) {
                printf("Stack is empty\n");
            } else {
                for(int j = top; j >= 0; j--) {
                    printf("%d ", stack[j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}