/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode* queue[100000];
    struct TreeLinkNode *p, *q;
    int head, tail, boundry;

    if (root == NULL) {
        return;
    }

    head = tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        boundry = tail;

        while (head < boundry) {
            p = queue[head];
            q = queue[head + 1];
            p->next = q;

            if (p->left) {
                queue[tail++] = p->left;
            }

            if (p->right) {
                queue[tail++] = p->right;
            }

            head++;
        }

        p = queue[boundry - 1];
        p -> next = NULL;
    }
}
