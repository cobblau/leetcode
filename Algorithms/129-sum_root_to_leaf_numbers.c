/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode *root) {
    return dfs(root, 0);
}
int dfs(struct TreeNode* root, int num) {
    if (root == NULL) {
        return 0;
    }

    num = 10 * num + root->val;

    if (!root->left && !root->right) {
        return num;
    }

    return dfs(root->left, num) + dfs(root->right, num);
}
