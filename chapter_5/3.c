#include <stdio.h>
#include <stdbool.h>
bool lemonadeChange(int *bills, int billsSize)
{
    int five = 0;
    int ten = 0;

    for (int i = 0; i < billsSize; i++)
    {

        if (bills[i] == 5)
            five++;
        else if (bills[i] == 10)
        {
            ten++;
            five--;
        }
        else
        {
            if (ten == 0)
                five = five - 3;
            else
            {
                ten--;
                five--;
            }
        }

        if (five < 0 || ten < 0)
            return false;
    }

    return true;
}

int main()
{
    int bills[1000] = {5, 5, 5, 10, 20};
    int length = 5;
    printf("%d", lemonadeChange(bills, length));
    return 0;
}
