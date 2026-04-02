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

int timeCounter;

void dfs(int u, int parent, struct Node* adj[], int visited[], int disc[], int low[], int ap[]) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;
    int children = 0;

    struct Node* temp = adj[u];
    while (temp) {
        int v = temp->data;

        if (!visited[v]) {
            children++;
            dfs(v, u, adj, visited, disc, low, ap);

            if (low[v] < low[u]) low[u] = low[v];

            if (parent != -1 && low[v] >= disc[u]) ap[u] = 1;
        } else if (v != parent) {
            if (disc[v] < low[u]) low[u] = disc[v];
        }

        temp = temp->next;
    }

    if (parent == -1 && children > 1) ap[u] = 1;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];
    for (int i = 0; i < V; i++) adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[V], disc[V], low[V], ap[V];

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        ap[i] = 0;
    }

    timeCounter = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, visited, disc, low, ap);
        }
    }

    int found = 0;
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) printf("-1");

    return 0;
}