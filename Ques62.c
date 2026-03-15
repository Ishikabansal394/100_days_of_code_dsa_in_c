#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    printf("enter string: ");
    scanf("%s", s);

    char stack[100];
    int top = -1;

    for(int i = 0; i < strlen(s); i++) {

        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }

        else {
            if(top == -1) {
                printf("Invalid");
                return 0;
            }

            char ch = stack[top--];

            if((s[i] == ')' && ch != '(') ||
               (s[i] == '}' && ch != '{') ||
               (s[i] == ']' && ch != '[')) {
                printf("Invalid");
                return 0;
            }
        }
    }

    if(top == -1)
        printf("Valid");
    else
        printf("Invalid");

    return 0;
}