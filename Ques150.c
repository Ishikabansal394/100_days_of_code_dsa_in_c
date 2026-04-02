#include <stdio.h>

#define MAX 1000

int color[MAX];

int dfs(int u, int graph[][MAX], int size[], int c) {
    color[u] = c;

    for (int i = 0; i < size[u]; i++) {
        int v = graph[u][i];

        if (color[v] == -1) {
            if (!dfs(v, graph, size, 1 - c)) return 0;
        } else if (color[v] == c) {
            return 0;
        }
    }
    return 1;
}

int isBipartite(int n, int graph[][MAX], int size[]) {
    for (int i = 0; i < n; i++) color[i] = -1;

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, graph, size, 0)) return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int graph[MAX][MAX];
    int size[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &size[i]);
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isBipartite(n, graph, size))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}