#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define INF 1000000000

struct Edge {
    int to, weight;
    struct Edge* next;
};

struct Edge* newEdge(int to, int w) {
    struct Edge* e = (struct Edge*)malloc(sizeof(struct Edge));
    e->to = to;
    e->weight = w;
    e->next = NULL;
    return e;
}

void addEdge(struct Edge* adj[], int u, int v, int w) {
    struct Edge* e = newEdge(v, w);
    e->next = adj[u];
    adj[u] = e;

    e = newEdge(u, w);
    e->next = adj[v];
    adj[v] = e;
}

struct HeapNode {
    int v, dist;
};

struct MinHeap {
    struct HeapNode arr[MAX];
    int size;
};

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(struct MinHeap* h, int i) {
    while (i > 0 && h->arr[(i - 1) / 2].dist > h->arr[i].dist) {
        swap(&h->arr[(i - 1) / 2], &h->arr[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(struct MinHeap* h, int i) {
    while (1) {
        int smallest = i;
        int l = 2 * i + 1, r = 2 * i + 2;

        if (l < h->size && h->arr[l].dist < h->arr[smallest].dist) smallest = l;
        if (r < h->size && h->arr[r].dist < h->arr[smallest].dist) smallest = r;

        if (smallest == i) break;

        swap(&h->arr[i], &h->arr[smallest]);
        i = smallest;
    }
}

void push(struct MinHeap* h, int v, int dist) {
    h->arr[h->size].v = v;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

struct HeapNode pop(struct MinHeap* h) {
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Edge* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int src;
    scanf("%d", &src);

    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INF;

    struct MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    push(&heap, src, 0);

    while (heap.size > 0) {
        struct HeapNode node = pop(&heap);
        int u = node.v;
        int d = node.dist;

        if (d > dist[u]) continue;

        struct Edge* temp = adj[u];
        while (temp) {
            int v = temp->to;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }

    return 0;
}