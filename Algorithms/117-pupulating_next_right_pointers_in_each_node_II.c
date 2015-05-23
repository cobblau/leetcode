/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
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
