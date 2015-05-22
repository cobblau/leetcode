/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int depth(struct TreeNode *root) {
    if (!root) return 0;
    return depth(root->left) > depth(root->right) ? depth(root->left) + 1 : depth(root->right) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (!root) return true;

    return isBalanced(root->left) &&
        isBalanced(root->right) &&
        abs(depth(root->left) - depth(root->right)) <= 1;
}
