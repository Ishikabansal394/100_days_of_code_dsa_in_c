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

    int sum = 0;
    int max = a[0];

    for(int i = 0; i < n; i++) {
        sum = sum + a[i];

        if(sum > max) {
            max = sum;
        }

        if(sum < 0) {
            sum = 0;
        }
    }
    printf("Max sum: %d", max);
    return 0;
}