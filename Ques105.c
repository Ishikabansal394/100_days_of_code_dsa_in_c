#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node *left, *right;
};

struct Pair {
    struct Node* node;
    int hd;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    struct Pair queue[MAX];
    int front = 0, rear = 0;

    int min = 0, max = 0;

    int cols[2001][MAX];
    int count[2001] = {0};

    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {
        struct Pair p = queue[front++];
        struct Node* node = p.node;
        int hd = p.hd;

        int idx = hd + 1000;

        cols[idx][count[idx]++] = node->data;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (node->left)
            queue[rear++] = (struct Pair){node->left, hd - 1};

        if (node->right)
            queue[rear++] = (struct Pair){node->right, hd + 1};
    }

    for (int i = min; i <= max; i++) {
        int idx = i + 1000;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", cols[idx][j]);
        }
        printf("\n");
    }

    return 0;
}