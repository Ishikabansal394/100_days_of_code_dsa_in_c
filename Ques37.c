#include <stdio.h>
#include <stdlib.h>  

int main() {
    int n;

    printf("enter size: ");
    scanf("%d", &n);

    int a[n];

    printf("enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int minSum = 1000000;
    int x, y;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {

            int sum = a[i] + a[j];

            if(abs(sum) < abs(minSum)) {
                minSum = sum;
                x = a[i];
                y = a[j];
            }
        }
    }

    printf("pair: %d %d", x, y);

    return 0;
}