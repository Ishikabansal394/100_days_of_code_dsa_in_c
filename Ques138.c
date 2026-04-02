#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define INF 1000000000

struct Edge {
    int to, w;
    struct Edge* next;
};

struct Edge* newEdge(int to, int w) {
    struct Edge* e = (struct Edge*)malloc(sizeof(struct Edge));
    e->to = to;
    e->w = w;
    e->next = NULL;
    return e;
}

void addEdge(struct Edge* adj[], int u, int v, int w) {
    struct Edge* e = newEdge(v, w);
    e->next = adj[u];
    adj[u] = e;
}

struct Node {
    int v, dist;
};

struct Heap {
    struct Node arr[MAX];
    int size;
};

void swap(struct Node* a, struct Node* b) {
    struct Node t = *a;
    *a = *b;
    *b = t;
}

void up(struct Heap* h, int i) {
    while (i > 0 && h->arr[(i-1)/2].dist > h->arr[i].dist) {
        swap(&h->arr[(i-1)/2], &h->arr[i]);
        i = (i-1)/2;
    }
}

void down(struct Heap* h, int i) {
    while (1) {
        int s = i, l = 2*i+1, r = 2*i+2;

        if (l < h->size && h->arr[l].dist < h->arr[s].dist) s = l;
        if (r < h->size && h->arr[r].dist < h->arr[s].dist) s = r;

        if (s == i) break;

        swap(&h->arr[i], &h->arr[s]);
        i = s;
    }
}

void push(struct Heap* h, int v, int d) {
    h->arr[h->size].v = v;
    h->arr[h->size].dist = d;
    up(h, h->size);
    h->size++;
}

struct Node pop(struct Heap* h) {
    struct Node t = h->arr[0];
    h->arr[0] = h->arr[h->size-1];
    h->size--;
    down(h, 0);
    return t;
}

int networkDelayTime(int times[][3], int size, int n, int k) {
    struct Edge* adj[n+1];
    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < size; i++) {
        addEdge(adj, times[i][0], times[i][1], times[i][2]);
    }

    int dist[n+1];
    for (int i = 1; i <= n; i++) dist[i] = INF;

    struct Heap h;
    h.size = 0;

    dist[k] = 0;
    push(&h, k, 0);

    while (h.size > 0) {
        struct Node cur = pop(&h);
        int u = cur.v;

        if (cur.dist > dist[u]) continue;

        struct Edge* temp = adj[u];
        while (temp) {
            int v = temp->to;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) return -1;
        if (dist[i] > ans) ans = dist[i];
    }

    return ans;
}

int main() {
    int times[][3] = {{2,1,1},{2,3,1},{3,4,1}};
    int size = 3, n = 4, k = 2;

    printf("%d\n", networkDelayTime(times, size, n, k));

    return 0;
}