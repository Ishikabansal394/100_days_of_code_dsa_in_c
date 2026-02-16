#include <stdio.h>

int main() {
    int m, n;
    printf("Enter dimensions: ");
    scanf("%d %d", &m, &n);

    int arr[m][n];
    int sum = 0;
    printf("Enter matrix elements:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < m && i < n; i++) {
        sum += arr[i][i];
    }

    printf("%d\n", sum);

    return 0;
}