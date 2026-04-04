#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int canSplit(int nums[], int n, int k, int maxSum) {
    int parts = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > maxSum) return 0;

        if (sum + nums[i] <= maxSum) {
            sum += nums[i];
        } else {
            parts++;
            sum = nums[i];
        }
    }

    return parts <= k;
}

int splitArray(int nums[], int n, int k) {
    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        left = max(left, nums[i]);
        right += nums[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canSplit(nums, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    int nums[] = {7,2,5,10,8};
    int n = 5;
    int k = 2;

    printf("%d\n", splitArray(nums, n, k));

    return 0;
}