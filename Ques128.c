#include <stdio.h>

#define MAX 1000

int orangesRotting(int grid[][MAX], int m, int n) {
    int queue[MAX][2];
    int front = 0, rear = 0;

    int fresh = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int time = 0;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (front < rear && fresh > 0) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            int r = queue[front][0];
            int c = queue[front][1];
            front++;

            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d][0];
                int nc = c + dirs[d][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    queue[rear][0] = nr;
                    queue[rear][1] = nc;
                    rear++;
                    fresh--;
                }
            }
        }
        time++;
    }

    return fresh == 0 ? time : -1;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int grid[MAX][MAX];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);

    printf("%d\n", orangesRotting(grid, m, n));

    return 0;
}