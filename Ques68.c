#include <stdio.h>
#include <ctype.h>

int main() {
    char s[100];
    printf("enter expression: ");
    scanf(" %[^\n]", s);

    int stack[100], top = -1;
    int num = 0;
    char op = '+';

    for(int i = 0; s[i] != '\0'; i++) {

        if(isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        // if operator OR end
        if((!isdigit(s[i]) && s[i] != ' ') || s[i+1] == '\0') {

            if(op == '+') {
                stack[++top] = num;
            }
            else if(op == '-') {
                stack[++top] = -num;
            }
            else if(op == '*') {
                stack[top] = stack[top] * num;
            }
            else if(op == '/') {
                stack[top] = stack[top] / num;
            }

            op = s[i];
            num = 0;
        }
    }

    // sum all values
    int result = 0;
    for(int i = 0; i <= top; i++) {
        result += stack[i];
    }

    printf("result: %d", result);
    return 0;
}