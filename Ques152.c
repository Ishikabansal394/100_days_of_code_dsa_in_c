
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int val;
    int size;
    struct Node** neighbors;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->size = 0;
    node->neighbors = (struct Node**)malloc(sizeof(struct Node*) * MAX);
    return node;
}

struct Node* visited[MAX];

struct Node* dfs(struct Node* node) {
    if (!node) return NULL;

    if (visited[node->val]) return visited[node->val];

    struct Node* clone = createNode(node->val);
    visited[node->val] = clone;

    for (int i = 0; i < node->size; i++) {
        clone->neighbors[clone->size++] = dfs(node->neighbors[i]);
    }

    return clone;
}

struct Node* cloneGraph(struct Node* node) {
    for (int i = 0; i < MAX; i++) visited[i] = NULL;
    return dfs(node);
}

int main() {
    struct Node* n1 = createNode(1);
    struct Node* n2 = createNode(2);
    struct Node* n3 = createNode(3);
    struct Node* n4 = createNode(4);

    n1->neighbors[n1->size++] = n2;
    n1->neighbors[n1->size++] = n4;

    n2->neighbors[n2->size++] = n1;
    n2->neighbors[n2->size++] = n3;

    n3->neighbors[n3->size++] = n2;
    n3->neighbors[n3->size++] = n4;

    n4->neighbors[n4->size++] = n1;
    n4->neighbors[n4->size++] = n3;

    struct Node* clone = cloneGraph(n1);

    printf("%d\n", clone->val);

    return 0;
}