#include <stdio.h>

int main() {
    int n;

    printf("enter n: ");
    scanf("%d", &n);

    int stack[100];
    int top = -1;

    printf("enter elements: ");
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        top++;
        stack[top] = x;  
    }

    int m;
    printf("enter m (pops): ");
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        if(top == -1) {
            printf("Stack Underflow\n");
            return 0;
        }
        top--;
    }

    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}