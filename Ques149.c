#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int prefix = 0;
    int maxLen = 0;

    int sum[MAX * 10];
    int index[MAX * 10];

    for (int i = 0; i < MAX * 10; i++) index[i] = -1;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        if (prefix == 0) {
            maxLen = i + 1;
        }

        int key = prefix + 5000;

        if (index[key] != -1) {
            int len = i - index[key];
            if (len > maxLen) maxLen = len;
        } else {
            index[key] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}