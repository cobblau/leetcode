/*
Description:

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    struct TreeNode* queue[100000];
    struct TreeNode *p;
    int head, tail, boundry, depth;

    if (root == NULL) {
        return 0;
    }

    head = tail = depth = 0;

    queue[tail++] = root;

    while (head < tail) {
        boundry = tail;

        while (head < boundry) {
            p = queue[head++];

            if (p->left) {
                queue[tail++] = p->left;
            }

            if (p->right) {
                queue[tail++] = p->right;
            }
        }

        depth++;
    }

    return depth;
}

/*  below is a after Order traverse
int afterOrder(struct TreeNode* root) {
    struct TreeNode* stack[2048];
    int pos = 0, max = 0;
    struct TreeNode *p, *pre = NULL;

    if (root == NULL)
        return 0;

    stack[pos++] = root;

    while (pos > 0) {

        p = stack[pos - 1];
        if ((p->left == NULL && p->right == NULL) ||
            (pre != NULL && (pre == p->left || pre == p->right))) {
            pos--;
            pre = p;
            visit(p);
            continue;
        }

        if (p->right)
            stack[pos++] = p->right;
        if (p->left)
            stack[pos++] = p->left;
    }

    return max;
}
*/
