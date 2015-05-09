/*
Given a linked list, determine if it has a cycle in it.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *s, *f;

    s = f = head;

    while (f) {
        s = s->next;
        f = f->next;
        if (f)
            f = f->next;

        if (f && f == s)
            return true;
    }

    return false;
}
