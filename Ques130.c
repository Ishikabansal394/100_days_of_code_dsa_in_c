#include <stdio.h>
#include <stdlib.h>

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

int dfs(int v, int parent, struct Node* adj[], int visited[]) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->data;

        if (!visited[u]) {
            if (dfs(u, v, adj, visited)) return 1;
        } else if (u != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int hasCycle(int V, struct Node* adj[]) {
    int visited[V];
    for (int i = 0; i < V; i++) visited[i] = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) return 1;
        }
    }
    return 0;
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

    if (hasCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}