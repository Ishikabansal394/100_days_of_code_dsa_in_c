#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int start[n], end[n];

    for (int i = 0; i < n; i++) scanf("%d", &start[i]);
    for (int i = 0; i < n; i++) scanf("%d", &end[i]);

    qsort(start, n, sizeof(int), cmp);
    qsort(end, n, sizeof(int), cmp);

    int i = 0, j = 0;
    int rooms = 0, maxRooms = 0;

    while (i < n && j < n) {
        if (start[i] >= end[j]) {
            rooms--;
            j++;
        } else {
            rooms++;
            i++;
            if (rooms > maxRooms) maxRooms = rooms;
        }
    }

    printf("%d\n", maxRooms);

    return 0;
}