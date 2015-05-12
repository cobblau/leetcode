/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

/*
 f(n) = f(n-1) + f(n-2)
*/
int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }

    if (n == 2) {
        return 2;
    }

    int mi = 1, mii = 2, tmp;
    for (int i = 3; i <= n ; i++) {
        tmp = mi + mii;
        mi = mii;
        mii = tmp;
    }

    return mii;
}
