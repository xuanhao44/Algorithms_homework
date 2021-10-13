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
    int coinsSize;
    int amount;
    int coins[15];
    scanf("%d %d",&coinsSize,&amount);
    for(int i = 0; i <= coinsSize - 1; i++){
        scanf("%d",&coins[i]);
    }
    printf("%d",coinChange(coins,coinsSize,amount));
    return 0;
}
