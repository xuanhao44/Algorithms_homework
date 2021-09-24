#include <stdio.h>
int FindEqual(int A[], int first, int last)
{
    int n = last - first + 1;
    int mid;
    if (n == 1)
        return A[first] == first;
    if (n % 2)
    {
        mid = (first + last) / 2;
        if (A[mid] == mid)
            return 1;
        else if (A[mid] > mid)
            return FindEqual(A, first, mid - 1);
        else
            return FindEqual(A, mid + 1, last);
    }
    if (!(n % 2))
    {
        mid = (first + last - 1) / 2;
        if (A[mid] == mid)
            return 1;
        else if (A[mid] > mid)
            return FindEqual(A, first, mid - 1);
        else
            return FindEqual(A, mid + 1, last);
    }
}
int main()
{
    //每个都符合
    int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d\n", FindEqual(A, 0, 9));

    //只有B[0]=0
    int B[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    printf("%d\n", FindEqual(B, 0, 9));

    //都不符合
    int C[10] = {1, 2, 3, 4, 5, 6, 7, 7, 9, 10};
    printf("%d\n", FindEqual(C, 0, 9));
    return 0;
}
