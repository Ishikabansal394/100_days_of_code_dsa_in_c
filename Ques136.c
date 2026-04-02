#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = newNode(v);
    node->next = adj[u];
    adj[u] = node;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    int indegree[n];
    for (int i = 0; i < n; i++) indegree[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        indegree[v]++;
    }

    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        struct Node* temp = adj[v];
        while (temp) {
            indegree[temp->data]--;
            if (indegree[temp->data] == 0) {
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }

    if (count != n) {
        printf("\nCycle exists");
    }

    return 0;
}