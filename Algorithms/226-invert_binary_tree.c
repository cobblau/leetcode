/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:
Invert a binary tree.

     4096   /   \
  2     7
 / \   / \
1   3 6   9
to
     4096   /   \
  7     2
 / \   / \
9   6 3   1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode *l = invertTree(root->left);
    struct TreeNode *r = invertTree(root->right);
    root->left = r;
    root->right = l;

    return root;
}

struct TreeNode* invertTree2(struct TreeNode* root) {
    struct TreeNode *stack[4096], *p, *t;
    int pos = 0;

    stack[pos++] = root;

    while (pos) {
        p = stack[--pos];

        if (p) {
            t = p->left;
            p->left = p->right;
            p->right = t;

            stack[pos++] = p->left;
            stack[pos++] = p->right;
        }
    }

    return root;
}
