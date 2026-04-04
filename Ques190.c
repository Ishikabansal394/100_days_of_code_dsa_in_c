#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int maximumGap(int nums[], int n) {
    if (n < 2) return 0;

    int mn = nums[0], mx = nums[0];

    for (int i = 1; i < n; i++) {
        mn = min(mn, nums[i]);
        mx = max(mx, nums[i]);
    }

    if (mn == mx) return 0;

    int bucketSize = max(1, (mx - mn) / (n - 1));
    int bucketCount = (mx - mn) / bucketSize + 1;

    int *bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int *bucketMax = (int*)malloc(bucketCount * sizeof(int));
    int *used = (int*)calloc(bucketCount, sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INF;
        bucketMax[i] = -INF;
    }

    for (int i = 0; i < n; i++) {
        int idx = (nums[i] - mn) / bucketSize;
        bucketMin[idx] = min(bucketMin[idx], nums[i]);
        bucketMax[idx] = max(bucketMax[idx], nums[i]);
        used[idx] = 1;
    }

    int prev = mn;
    int ans = 0;

    for (int i = 0; i < bucketCount; i++) {
        if (!used[i]) continue;

        ans = max(ans, bucketMin[i] - prev);
        prev = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);
    free(used);

    return ans;
}

int main() {
    int nums[] = {3,6,9,1};
    int n = 4;

    printf("%d\n", maximumGap(nums, n));

    return 0;
}