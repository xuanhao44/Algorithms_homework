#include <stdio.h>
int MidSearch(int A[], int B[], int n)
{
    int firstA = 0;
    int lastA = n - 1;
    int firstB = 0;
    int lastB = n - 1;
    int midA, midB;

    while ((firstA != lastA) || firstB != lastB)
    {
        midA = firstA + (lastA - firstA) / 2;
        midB = firstB + (lastB - firstB) / 2;

        if (A[midA] == B[midB])
            return A[midA];
        else if (A[midA] < B[midB])
        {
            if ((lastA - firstA + 1) % 2)
            {
                lastB = midB;
                firstA = midA;
            }
            else
            {
                lastB = midB;
                firstA = midA + 1;
            }
        }
        else
        {
            if ((lastB - firstB + 1) % 2)
            {
                lastA = midA;
                firstB = midB;
            }
            else
            {
                lastA = midA;
                firstB = midB + 1;
            }
        }
    }
    if (A[firstA] < B[firstB])
        return A[firstA];
    else
        return B[firstB];
}

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int B[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    printf("%d", MidSearch(A, B, 10));
    return 0;
}
