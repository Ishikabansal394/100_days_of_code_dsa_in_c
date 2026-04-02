#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define INF 1000000000

int absVal(int x) {
    return x < 0 ? -x : x;
}

int minCostConnectPoints(int points[][2], int n) {
    int minDist[MAX];
    int visited[MAX];

    for (int i = 0; i < n; i++) {
        minDist[i] = INF;
        visited[i] = 0;
    }

    minDist[0] = 0;
    int result = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        result += minDist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int cost = absVal(points[u][0] - points[v][0]) +
                           absVal(points[u][1] - points[v][1]);

                if (cost < minDist[v]) {
                    minDist[v] = cost;
                }
            }
        }
    }

    return result;
}

int main() {
    int points[][2] = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    int n = 5;

    printf("%d\n", minCostConnectPoints(points, n));

    return 0;
}