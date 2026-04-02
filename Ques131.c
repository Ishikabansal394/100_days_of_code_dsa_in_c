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
}

int dfs(int v, struct Node* adj[], int visited[], int rec[]) {
    visited[v] = 1;
    rec[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->data;

        if (!visited[u]) {
            if (dfs(u, adj, visited, rec)) return 1;
        } else if (rec[u]) {
            return 1;
        }

        temp = temp->next;
    }

    rec[v] = 0;
    return 0;
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

    int visited[n], rec[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        rec[i] = 0;
    }

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, rec)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle) printf("YES");
    else printf("NO");

    return 0;
}