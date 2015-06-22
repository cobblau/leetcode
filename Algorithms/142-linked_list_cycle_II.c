/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*/

/**
 * Definition for singly-linked list.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow, *fast;

    slow = fast = head;

    while (slow && fast) {
        slow = slow->next;
        fast = fast->next;

        if (fast) {
            fast = fast->next;
        }

        if (slow == fast) {
            break;
        }
    }

    if (fast == NULL) {
        return NULL;
    }

    slow = head;
    while (fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
