#include <stdio.h>
#include <stdlib.h>

struct Node {
    float val;
    struct Node* next;
};

struct Node* newNode(float x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = x;
    node->next = NULL;
    return node;
}

void insertSorted(struct Node** head, float x) {
    struct Node* node = newNode(x);

    if (*head == NULL || (*head)->val >= x) {
        node->next = *head;
        *head = node;
        return;
    }

    struct Node* curr = *head;
    while (curr->next && curr->next->val < x) {
        curr = curr->next;
    }

    node->next = curr->next;
    curr->next = node;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) scanf("%f", &arr[i]);

    struct Node* buckets[n];
    for (int i = 0; i < n; i++) buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int idx = arr[i] * n;
        insertSorted(&buckets[idx], arr[i]);
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp) {
            arr[k++] = temp->val;
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%.6f ", arr[i]);
    }

    return 0;
}