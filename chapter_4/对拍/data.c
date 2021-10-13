#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    int testcase = 100;
    srand(time(NULL));
    int coins[100];
    int coinsSize;
    int amount;
    while(testcase--){
        coinsSize = rand()%12 + 1;
        amount = rand()%10000;
        for(int i = 0; i <= coinsSize; i++){
        	coins[i] = rand()%2147483647 + 1;
		}
        printf("%d %d\n",coinsSize,amount);
        for(int i = 0; i <= coinsSize; i++)
        printf("%d ",coins[i]);
        printf("\n");
    }
    return 0;
}
