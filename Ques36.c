#include <stdio.h>

int main() {
    int n;

    printf("enter size: ");
    scanf("%d", &n);

    int a[n], res[n];

    printf("enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++) {
        int prod = 1;

        for(int j = 0; j < n; j++) {
            if(j != i) {
                prod = prod * a[j];
            }
        }

        res[i] = prod;
    }

    printf("result: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}