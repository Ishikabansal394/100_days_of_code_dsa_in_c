#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int arr[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == val) return i;
    }
    return -1;
}

struct Node* build(int inorder[], int postorder[], int inStart, int inEnd, int *postIndex) {
    if (inStart > inEnd) return NULL;

    int val = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = newNode(val);

    if (inStart == inEnd) return root;

    int idx = findIndex(inorder, inStart, inEnd, val);

    root->right = build(inorder, postorder, idx + 1, inEnd, postIndex);
    root->left = build(inorder, postorder, inStart, idx - 1, postIndex);

    return root;
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = build(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}