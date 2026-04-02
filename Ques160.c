#include <stdio.h>

#define MAX 100
#define INF 1000000000

int main() {
    int n, m, threshold;
    scanf("%d %d %d", &n, &m, &threshold);

    int dist[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = w;
        dist[v][u] = w;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int minReach = INF;
    int city = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= threshold)
                count++;
        }

        if (count <= minReach) {
            minReach = count;
            city = i;
        }
    }

    printf("%d\n", city);

    return 0;
}