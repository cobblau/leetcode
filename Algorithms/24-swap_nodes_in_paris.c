/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *h, *pre, *post, *t;

    if (head == NULL || head->next == NULL) {
        return head;
    }

    t = NULL;
    pre = head;
    h = post = head->next;

    while (pre && post) {
        if (t != NULL) {
            t->next = post;
        }

        pre->next = post->next;
        post->next = pre;

        t = pre;

        pre = pre->next;
        if (pre) {
            post = pre->next;
        }
    }

    return h;
}
