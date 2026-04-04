#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int canShip(int weights[], int n, int days, int cap) {
    int d = 1;
    int load = 0;

    for (int i = 0; i < n; i++) {
        if (load + weights[i] <= cap) {
            load += weights[i];
        } else {
            d++;
            load = weights[i];
        }
    }

    return d <= days;
}

int shipWithinDays(int weights[], int n, int days) {
    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        left = max(left, weights[i]);
        right += weights[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canShip(weights, n, days, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    int weights[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    int days = 5;

    printf("%d\n", shipWithinDays(weights, n, days));

    return 0;
}