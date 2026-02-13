#include <stdio.h>
#include <string.h>

void reverseString(char s[], int size) {
    int i = 0, j = size - 1;
    char temp;

    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char s[100000];
    printf("enter string : ");
    scanf("%s", s);
    int n = strlen(s);

    reverseString(s, n);

    printf("%s", s);  
    return 0;
}