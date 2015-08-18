/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */


/*
Description:

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

int min(int a, int b) {
    return a > b ? b : a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize) {
    int *lprofit = (int *) malloc(pricesSize * sizeof(int));
    int *rprofit = (int *) malloc(pricesSize * sizeof(int));

    int m = prices[0];
    lprofit[0] = 0;
    for (int i = 1; i < pricesSize; i++) {
        m = min(m, prices[i]);
        lprofit[i] = max(lprofit[i-1], prices[i] - m);
    }

    m = prices[pricesSize-1];
    rprofit[pricesSize-1] = 0;
    for (int i = pricesSize-2; i >= 0; i--) {
        m = max(m, prices[i]);
        rprofit[i] = max(rprofit[i+1], m - prices[i]);
    }

    int best = 0;
    for (int i = 0; i < pricesSize; i++) {
        best = max(lprofit[i] + rprofit[i], best);
    }

    free(lprofit);
    free(rprofit);

    return best;
}
