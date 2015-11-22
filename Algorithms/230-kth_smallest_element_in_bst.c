/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode *root, int k, int *ans) {
    if (root == NULL) {
        return 0;
    }

    int lc = height(root->left, k, ans);
    if (k == lc + 1) {
        *ans = root->val;
    }

    int rc = height(root->right, k - lc - 1, ans);

    return lc + rc + 1;
}

int kthSmallest(struct TreeNode* root, int k) {
    int ans = 0;

    height(root, k, &ans);

    return ans;
}
