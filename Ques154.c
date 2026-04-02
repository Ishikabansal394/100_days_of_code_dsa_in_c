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

    node = newNode(u);
    node->next = adj[v];
    adj[v] = node;
}

int timeCounter = 0;

void dfs(int u, int parent, struct Node* adj[], int visited[], int disc[], int low[]) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    struct Node* temp = adj[u];
    while (temp) {
        int v = temp->data;

        if (v == parent) {
            temp = temp->next;
            continue;
        }

        if (!visited[v]) {
            dfs(v, u, adj, visited, disc, low);

            if (low[v] > disc[u]) {
                printf("%d %d\n", u, v);
            }

            if (low[v] < low[u]) low[u] = low[v];
        } else {
            if (disc[v] < low[u]) low[u] = disc[v];
        }

        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n], disc[n], low[n];

    for (int i = 0; i < n; i++) visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, visited, disc, low);
        }
    }

    return 0;
}