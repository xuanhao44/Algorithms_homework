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
    int m[amount + 2];
    for (int i = 1; i <= amount; i++)
        m[i] = MAX_NUM;

    m[0] = 0;
    for (int i = 1; i <= n; i++)
        m[coins[i]] = 1;
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
    printf("%d\n", mininum(coins1, 3, amount1));
    printf("%d\n", mininum(coins2, 1, amount2));
    return 0;
}
