#include <stdio.h>

#define MAX 200

void dfs(int i, int n, int isConnected[][MAX], int visited[]) {
    visited[i] = 1;

    for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
            dfs(j, n, isConnected, visited);
        }
    }
}

int findCircleNum(int n, int isConnected[][MAX]) {
    int visited[MAX] = {0};
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, isConnected, visited);
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int isConnected[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &isConnected[i][j]);

    printf("%d\n", findCircleNum(n, isConnected));

    return 0;
}