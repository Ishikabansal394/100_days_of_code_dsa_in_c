#include <stdio.h>

int main() {
    int m, n;
   
    printf("enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[100][100];
    int row[100], col[100];


    for(int i = 0; i < m; i++) {
        row[i] = 0;
    }
    for(int j = 0; j < n; j++) {
        col[j] = 0;
    }
    printf("enter elements:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(row[i] == 1 || col[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
    printf("result matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}