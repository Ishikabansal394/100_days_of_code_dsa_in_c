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

int canFinish(int numCourses, int prerequisites[][2], int size) {
    struct Node* adj[numCourses];
    for (int i = 0; i < numCourses; i++) adj[i] = NULL;

    for (int i = 0; i < size; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        addEdge(adj, b, a);
    }

    int visited[numCourses], rec[numCourses];
    for (int i = 0; i < numCourses; i++) {
        visited[i] = 0;
        rec[i] = 0;
    }

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, rec)) return 0;
        }
    }

    return 1;
}

int main() {
    int numCourses = 2;
    int prerequisites[][2] = {{1,0}};
    int size = 1;

    if (canFinish(numCourses, prerequisites, size))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}