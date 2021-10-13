#include <stdio.h>
const int MAX_NUM = 100000;

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

int mininum(int coins[], int n, int amount)
{
    if (amount == 0)
        return 0;
    int m[amount + 2];
    // 初始化为一个较大的值, 若此值最后未更新说明没有硬币组合能凑出面额 i
    for (int i = 1; i <= amount; i++)
        m[i] = MAX_NUM;
    // m[0]只会出现于 m[i] = m[0] + m[i], 故设为 0, 便于计算
    m[0] = 0;
    // 所有在 coins 数组中出现过的硬币面额, 达到这个面额所需的最小硬币数量一定是 1
    // 如 coins 数组中有 10, 则一定有 m[10] = 1
    for (int i = 1; i <= n; i++)
    {
        if (coins[i] <= amount)
            m[coins[i]] = 1;
    }

    for (int i = 1; i <= amount; i++)
        for (int k = 0; k <= i / 2; k++)
            m[i] = min(m[i], m[k] + m[i - k]);

    if (m[amount] == MAX_NUM)
        return -1;
    else
        return m[amount];
}

int main()
{
    int coins1[4] = {0, 1, 2, 5};
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

    printf("%d\n", mininum(coins1, 3, amount1));
    printf("%d\n", mininum(coins2, 1, amount2));
    printf("%d\n", mininum(coins3, 8, amount3));
    printf("%d\n", mininum(coins4, 8, amount4));
    printf("%d\n", mininum(coins5, 8, amount5));
    printf("%d\n", mininum(coins6, 8, amount6));
    printf("%d\n", mininum(coins7, 1, amount7));
    return 0;
}
