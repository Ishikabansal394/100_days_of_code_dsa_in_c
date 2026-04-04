#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int pos[], int n, int m, int dist) {
    int count = 1;
    int last = pos[0];

    for (int i = 1; i < n; i++) {
        if (pos[i] - last >= dist) {
            count++;
            last = pos[i];
            if (count >= m) return 1;
        }
    }
    return 0;
}

int maxDistance(int pos[], int n, int m) {
    qsort(pos, n, sizeof(int), cmp);

    int left = 1;
    int right = pos[n - 1] - pos[0];
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlace(pos, n, m, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int pos[] = {1,2,8,4,9};
    int n = 5;
    int m = 3;

    printf("%d\n", maxDistance(pos, n, m));

    return 0;
}