#include <stdio.h>

int main() {
    int r, c;
    printf("Enter rows and cols: ");
    scanf("%d %d", &r, &c);

    int a[r][c];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int sr = 0, er = r - 1;
    int sc = 0, ec = c - 1;

    while(sr <= er && sc <= ec) {

        for(int j = sc; j <= ec; j++) {
            printf("%d ", a[sr][j]);
        }
        sr++;

        for(int i = sr; i <= er; i++) {
            printf("%d ", a[i][ec]);
        }
        ec--;

        if(sr <= er) {
            for(int j = ec; j >= sc; j--) {
                printf("%d ", a[er][j]);
            }
            er--;
        }
        if(sc <= ec) {
            for(int i = er; i >= sr; i--) {
                printf("%d ", a[i][sc]);
            }
            sc++;
        }
    }

    return 0;
}