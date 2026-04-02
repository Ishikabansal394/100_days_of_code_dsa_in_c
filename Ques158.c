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

void dfs1(int v, struct Node* adj[], int visited[], int stack[], int *top) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs1(temp->data, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[(*top)++] = v;
}

void dfs2(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs2(temp->data, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];
    struct Node* rev[V];

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        rev[i] = NULL;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(rev, v, u);
    }

    int visited[V];
    for (int i = 0; i < V; i++) visited[i] = 0;

    int stack[MAX], top = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, stack, &top);
        }
    }

    for (int i = 0; i < V; i++) visited[i] = 0;

    int scc = 0;

    for (int i = top - 1; i >= 0; i--) {
        int v = stack[i];
        if (!visited[v]) {
            dfs2(v, rev, visited);
            scc++;
        }
    }

    printf("%d\n", scc);

    return 0;
}