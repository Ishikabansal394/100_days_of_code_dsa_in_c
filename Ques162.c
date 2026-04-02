#include <stdio.h>

int search(int nums[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

int main() {
    int nums[] = {-1,0,3,5,9,12};
    int n = 6;
    int target = 9;

    printf("%d\n", search(nums, n, target));

    return 0;
}