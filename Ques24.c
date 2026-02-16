#include <stdio.h>

int main() {
    int m, n;

    printf("Enter rows and cols: ");
    scanf("%d %d", &m, &n);

    int A[m][n];

    printf("Enter matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(A[i][j] != A[i-1][j-1]) {
                printf("false");
                return 0;
            }
        }
    }

    printf("true");
    return 0;
}