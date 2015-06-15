/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

    Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

struct Elem {
    int val;
    struct Elem *next;
};

struct Hash {
    struct Elem **slots;
    int  cap;
};

int containsDuplicate(int* nums, int numsSize) {
    struct Elem *e;
    int ret = 0;

    struct Hash *set = (struct Hash*) malloc(sizeof(struct Hash));

    set->cap = numsSize;
    set->slots = (struct Elem **) calloc(sizeof(struct Elem *), set->cap);


    for (int i = 0; i < numsSize; i++) {
        int index = (unsigned int) nums[i] % set->cap;

        if (set->slots[index] == NULL) {
            e = (struct Elem*) malloc(sizeof(struct Elem));
            e->val = nums[i];
            e->next = NULL;

            set->slots[index] = e;
        } else {
            for (e = set->slots[index]; e; e = e->next) {
                if (e->val == nums[i]) {
                    ret = 1;
                    goto cleanup;
                }
            }

            e = (struct Elem*) malloc(sizeof(struct Elem));
            e->val = nums[i];
            e->next = set->slots[index];
            set->slots[index] = e;
        }
    }

 cleanup:

    for (int i = 0; i < set->cap; i++) {
        struct Elem *tmp = NULL;
        e = set->slots[i];
        while (e) {
            tmp = e;
            e = e->next;
            free(tmp);
        }
    }

    free(set->slots);
    free(set);

    return ret;
}
