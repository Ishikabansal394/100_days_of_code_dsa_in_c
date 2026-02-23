#include <stdio.h>

int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};

    for (int i = 0; i < size; i++) {
        freq[tasks[i] - 'A']++;
    }

    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    int countMax = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq) {
            countMax++;
        }
    }

    int part = (maxFreq - 1) * (n + 1) + countMax;

    return size > part ? size : part;
}

int main() {
    char tasks1[] = {'A','A','A','B','B','B'};
    int n1 = 2;
    printf("%d\n", leastInterval(tasks1, 6, n1));

    char tasks2[] = {'A','C','A','B','D','B'};
    int n2 = 1;
    printf("%d\n", leastInterval(tasks2, 6, n2));

    return 0;
}