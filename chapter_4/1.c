#include <stdio.h>
int stone_merge(int n, int w[])
{
    const int MAX_NUM = 100000;
    int dp[n + 2][n + 2];
    int R[n + 2][n + 2];
    int j, q;
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
        R[i][i] = w[i];
    }
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            dp[i][j] = MAX_NUM;
            R[i][j] = R[i][j - 1] + w[j];
            for (int k = i; k <= j - 1; k++)
            {
                q = dp[i][k] + dp[k + 1][j] + R[i][j];
                if (q < dp[i][j])
                {
                    dp[i][j] = q;
                }
            }
        }
    }
    return dp[1][n];
}
int main()
{
    int w[6] = {0, 1, 3, 5, 2, 4};
    printf("%d", stone_merge(5, w));
    return 0;
}
