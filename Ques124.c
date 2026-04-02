#include <stdio.h>

#define MAX 1000

void dfs(int room, int roomsSize, int rooms[][MAX], int colSize[], int visited[]) {
    visited[room] = 1;

    for (int i = 0; i < colSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(key, roomsSize, rooms, colSize, visited);
        }
    }
}

int canVisitAllRooms(int roomsSize, int rooms[][MAX], int colSize[]) {
    int visited[MAX] = {0};

    dfs(0, roomsSize, rooms, colSize, visited);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) return 0;
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int rooms[MAX][MAX];
    int colSize[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &colSize[i]);
        for (int j = 0; j < colSize[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    if (canVisitAllRooms(n, rooms, colSize))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}