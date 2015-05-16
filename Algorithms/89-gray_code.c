/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */


/*
 * Hint:
 * use reflect-and-prefix method mentioned in http://en.wikipedia.org/wiki/Gray_code
 */
int* grayCode(int n, int* returnSize) {

    int capacity = 1 << n;

    int *result = (int *) malloc(capacity * sizeof(int));
    int length = 0;

    result[length++] = 0;
    for (int i = 0; i < n; i++) {
        int prefix = 1 << i;

        int pos = length;
        for (int j = length - 1; j >= 0; j--) {
            result[pos++] = result[j] + prefix;
        }

        length <<= 1;
    }

    *returnSize = length;
    return result;
}
