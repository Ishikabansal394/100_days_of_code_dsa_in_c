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

int* findOrder(int numCourses, int prerequisites[][2], int size, int* returnSize) {
    struct Node* adj[numCourses];
    for (int i = 0; i < numCourses; i++) adj[i] = NULL;

    int indegree[numCourses];
    for (int i = 0; i < numCourses; i++) indegree[i] = 0;

    for (int i = 0; i < size; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        addEdge(adj, b, a);
        indegree[a]++;
    }

    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int* result = (int*)malloc(sizeof(int) * numCourses);
    int count = 0;

    while (front < rear) {
        int v = queue[front++];
        result[count++] = v;

        struct Node* temp = adj[v];
        while (temp) {
            indegree[temp->data]--;
            if (indegree[temp->data] == 0) {
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }

    if (count != numCourses) {
        *returnSize = 0;
        return result;
    }

    *returnSize = count;
    return result;
}

int main() {
    int numCourses = 4;
    int prerequisites[][2] = {{1,0},{2,0},{3,1},{3,2}};
    int size = 4;

    int returnSize;
    int* order = findOrder(numCourses, prerequisites, size, &returnSize);

    if (returnSize == 0) {
        printf("[]\n");
    } else {
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", order[i]);
        }
    }

    return 0;
}