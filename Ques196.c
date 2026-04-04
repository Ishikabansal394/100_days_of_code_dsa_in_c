#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval intervals[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    qsort(intervals, n, sizeof(Interval), cmp);

    Interval res[n];
    int idx = 0;

    res[idx] = intervals[0];

    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= res[idx].end) {
            if (intervals[i].end > res[idx].end)
                res[idx].end = intervals[i].end;
        } else {
            idx++;
            res[idx] = intervals[i];
        }
    }

    for (int i = 0; i <= idx; i++) {
        printf("[%d,%d] ", res[i].start, res[i].end);
    }

    return 0;
}