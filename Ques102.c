#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root) return NULL;

    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    return root;
}

struct TreeNode* search(struct TreeNode* root, int val) {
    if (!root || root->val == val) return root;

    if (val < root->val)
        return search(root->left, val);
    else
        return search(root->right, val);
}

int main() {
    struct TreeNode* root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(8);
    root->left->left = newNode(0);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->right->right = newNode(9);

    struct TreeNode* p = search(root, 2);
    struct TreeNode* q = search(root, 8);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca) printf("%d\n", lca->val);

    return 0;
}