/*
Description:

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }

    if (p == NULL && q != NULL) {
        return false;
    }

    if (p != NULL && q == NULL) {
        return false;
    }

    if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val) {
        return true;
    }

    return false;
}
