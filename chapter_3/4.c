#include <stdio.h>
int f(int A[], int first, int last)
{
    int n = last - first + 1;
    int mid;
    int sumleft = 0;
    int sumright = 0;
    if (n == 1)
        return first;
    if (n == 2)
    {
        if (A[first] > A[last])
            return last;
        else
            return first;
    }
    if (n % 2)
    {
        mid = (first + last) / 2;
        for (int i = 1; i <= (n - 1) / 2; i++)
        {
            sumleft += A[first - 1 + i];
            sumright += A[mid + i];
        }
        if (sumleft == sumright)
            return mid;
        else if (sumleft > sumright)
            return f(A, mid + 1, last);
        else
            return f(A, first, mid - 1);
    }
    if (!(n % 2))
    {
        mid = (first + last - 1) / 2;
        for (int i = 1; i <= n / 2; i++)
        {
            sumleft += A[first - 1 + i];
            sumright += A[mid + i];
        }
        if (sumleft > sumright)
            return f(A, mid + 1, last);
        else
            return f(A, first, mid);
    }
}

int main()
{
    int A[10] = {10, 10, 10, 10, 9, 10, 10, 10, 10, 10};
    printf("%d", f(A, 0, 9));
    return 0;
}
