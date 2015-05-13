/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */

/*
 Description:
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *walk, *cur, *head = NULL;

    if (!l1 || !l2) {
        return l1 ? l1 : l2;
    }

    for (; l1 && l2;) {
        if (l1->val <= l2->val) {
            cur = l1;
            l1 = l1->next;
        } else {
            cur = l2;
            l2 = l2->next;
        }

        if (head == NULL) {
            walk = head = cur;
        } else {
            walk->next = cur;
            walk = walk->next;
        }
    }

    walk->next = l1 ? l1 : l2;

    return head;
}
