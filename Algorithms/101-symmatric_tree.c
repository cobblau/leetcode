/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool check(struct TreeNode *l, struct TreeNode *r) {
    if (!l && !r) {
        return true;
    }

    if (!(l && r)) {
        return false;
    }

    if (l->val != r->val) {
        return false;
    }

    return check(l->left, r->right) && check(l->right, r->left);
}
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    return check(root->left, root->right);
}
