/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

    For example:

        1 -> A
        2 -> B
        3 -> C
        ...
        26 -> Z
        27 -> AA
        28 -> AB
*/

char* convertToTitle(int n) {
    int cur, i = 0, j = 0;
    char tmp[10];
    static char ret[10] = {'\0'};

    while (n) {
        n--;
        cur = n % 26;
        n = n / 26;

        tmp[i++] = 'A' + cur;
    }

    while (i >= 0) {
        ret[j++] = tmp[--i];
    }

    return ret;
}
