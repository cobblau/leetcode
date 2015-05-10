/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
 */

char* intToRoman(int num) {
    static char s[64] = {'\0'};
    char *p = s;

    while (num > 0)
        {
            if (num >= 1000) { *p++ = 'M'; num-=1000; continue;}
            if (num >= 900)  { *p++ = 'C'; *p++ = 'M'; num-=900; continue;}
            if (num >= 500)  { *p++ = 'D'; num-=500; continue;}
            if (num >= 400)  { *p++ = 'C'; *p++ = 'D'; num-=400; continue;}
            if (num >= 100)  { *p++ = 'C'; num-=100; continue;}
            if (num >= 90)   { *p++ = 'X'; *p++ = 'C'; num-=90; continue;}
            if (num >= 50)   { *p++ = 'L'; num-=50; continue;}
            if (num >= 40)   { *p++ = 'X'; *p++ = 'L'; num-=40; continue;}
            if (num >= 10)   { *p++ = 'X'; num-=10; continue;}
            if (num >= 9)    { *p++ = 'I'; *p++ = 'X'; num-=9; continue;}
            if (num >= 5)    { *p++ = 'V'; num-=5; continue;}
            if (num >= 4)    { *p++ = 'I'; *p++ = 'V'; num-=4; continue;}
            if (num == 3)    { *p++ = 'I'; *p++ = 'I'; *p++ = 'I'; num-=3; continue;}
            if (num == 2)    { *p++ = 'I'; *p++ = 'I'; num-=2; continue;}
            if (num == 1)    { *p++ = 'I'; num-=1; continue;}
    }

    return s;
}
