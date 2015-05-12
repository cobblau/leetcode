/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

int convert(char c) {
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }

    return 0;
}

int romanToInt(char* s) {
    int num;

    num = convert(*s++);

    while (*s != '\0') {
        int pre = convert(*(s-1));
        int cur = convert(*s);

        if (cur <= pre)
            num += cur;
        else
            num = num - 2 * pre + cur;

        s++;
    }

    return num;
}
