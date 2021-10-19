#include <stdio.h>
#include <stdlib.h>
int min(int a, int b)
{
    return (a < b) ? a : b;
}

int coinChange(int *coins, int coinsSize, int amount)
{
    int MAX_NUM = amount + 1;
    if (coins == NULL || coinsSize == 0 || amount < 0)  return -1;
    if (amount == 0) return 0;
    if (coinsSize == 1 && (amount % coins[0])) return -1;

    int dp[amount + 1];

    for (int i = 0; i <= amount; i++)
        dp[i] = MAX_NUM;
    dp[0] = 0;

    for (int i = 0; i <= amount; i++)
        for (int j = 0; j < coinsSize; j++)
        {
            if (i < coins[j]) continue;
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }

    return (dp[amount] == MAX_NUM) ? -1 : dp[amount];
}

int main()
{
    int coins1[4] = {1, 2, 5};
    int amount1 = 11;
    int coins2[2] = {2};
    int amount2 = 3;
    int coins3[9] = {328, 122, 26, 397, 252, 455, 250, 252};
    int amount3 = 7121;
    int coins4[9] = {430, 360, 440, 204, 206, 194, 150, 443};
    int amount4 = 3580;
    int coins5[9] = {259, 78, 94, 130, 493, 4, 168, 149};
    int amount5 = 4769;
    int coins6[9] = {244, 125, 459, 120, 316, 68, 357, 320};
    int amount6 = 9793;
    int coins7[2] = {2147483647}; //超大 coins 面额打击, 大于 amount 的 coins 直接不考虑
    int amount7 = 2;

    printf("%d\n", coinChange(coins1, 3, amount1));
    printf("%d\n", coinChange(coins2, 1, amount2));
    printf("%d\n", coinChange(coins3, 8, amount3));
    printf("%d\n", coinChange(coins4, 8, amount4));
    printf("%d\n", coinChange(coins5, 8, amount5));
    printf("%d\n", coinChange(coins6, 8, amount6));
    printf("%d\n", coinChange(coins7, 1, amount7));
    return 0;
}
