#include <stdio.h>

int main() {
    int n;

    printf("enter size: ");
    scanf("%d", &n);

    int a[n];

    printf("enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int i = 0, j = n - 1;

    while(i < j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }

    printf("reversed: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}