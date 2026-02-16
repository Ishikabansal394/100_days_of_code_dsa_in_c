#include <stdio.h>

int main() {
    int m, n;

    printf("Enter rows and cols: ");
    scanf("%d %d", &m, &n);

    int A[m][n], T[n][m];
    printf("Enter matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            T[j][i] = A[i][j];
        }
    }

    printf("Transpose:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

    return 0;
}