/*
 * Author: Cobbliu
 * Email: cobblau@gmail.com
 */

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) {
        return 0;
    }

    int best = 0, cur = 0;
    int min = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        cur = prices[i] - min;

        if (cur > best) {
            best = cur;
        }

        if (prices[i] < min) {
            min = prices[i];
        }
    }

    return best;
}
