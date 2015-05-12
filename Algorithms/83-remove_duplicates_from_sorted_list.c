/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p, *q;

    if (head == NULL) {
        return NULL;
    }

    p = head;
    q = p->next;

    while (q) {
        while (q && q->val == p->val) {
            q = q->next;
        }

        p->next = q;
        p = q;

        if (q) {
            q = q->next;
        }
    }

    return head;
}
