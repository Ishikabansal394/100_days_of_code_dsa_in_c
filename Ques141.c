#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[1000];

int hash(int key, int m) {
    return key % m;
}

void insert(int key, int m) {
    for (int i = 0; i < m; i++) {
        int idx = (hash(key, m) + i * i) % m;
        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
}

int search(int key, int m) {
    for (int i = 0; i < m; i++) {
        int idx = (hash(key, m) + i * i) % m;
        if (table[idx] == EMPTY) return 0;
        if (table[idx] == key) return 1;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    for (int i = 0; i < m; i++) table[i] = EMPTY;

    while (q--) {
        char op[10];
        int x;
        scanf("%s %d", op, &x);

        if (strcmp(op, "INSERT") == 0) {
            insert(x, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(x, m)) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    return 0;
}