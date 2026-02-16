#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int i = 0, j;

    printf("enter string : ");
    scanf("%s", s);

    j = strlen(s) - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            printf("NO");
            return 0;
        }
        i++;
        j--;
    }

    printf("YES");
    return 0;
}