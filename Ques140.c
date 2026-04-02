#include <stdio.h>

#define INF 1000000000

int findCheapestPrice(int n, int flights[][3], int size, int src, int dst, int k) {
    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INF;

    dist[src] = 0;

    for (int i = 0; i <= k; i++) {
        int temp[n];
        for (int j = 0; j < n; j++) temp[j] = dist[j];

        for (int j = 0; j < size; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] != INF && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        for (int j = 0; j < n; j++) dist[j] = temp[j];
    }

    return dist[dst] == INF ? -1 : dist[dst];
}

int main() {
    int flights[][3] = {{0,1,100},{1,2,100},{0,2,500}};
    int n = 3, size = 3;
    int src = 0, dst = 2, k = 1;

    printf("%d\n", findCheapestPrice(n, flights, size, src, dst, k));

    return 0;
}