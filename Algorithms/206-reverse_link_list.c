/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Reverse a singly linked list.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p, *q, *t;

    if (head == NULL) return NULL;

    p = head;
    q = head->next;
    p->next = NULL;

    while (q) {
        t = q->next;
        q->next = p;
        p = q;
        q = t;
    }

    return p;
}
