int shoppingOffers(int *price, int priceSize, int **special, int specialSize, int *specialColSize, int *needs, int needsSize)
{
    int mincost = 0;
    int cost = 0;
    int nowneeds[needsSize];

    // 一个可行解
    for (int i = 0; i < priceSize; i++)
        mincost += price[i] * needs[i];

    // 当都没有需要买的时候返回mincost,也即0
    if (mincost == 0)
        return mincost;

    for (int i = 0; i < specialSize; i++)
    {
        bool isGift = true;
        for (int j = 0; j < specialColSize[i] - 1; j++)
        {
            nowneeds[j] = needs[j] - special[i][j];
            cost += special[i][j] * price[j];
            // 若礼包中有比需要的物品数量多的则找寻下一个礼包
            if (nowneeds[j] < 0)
            {
                isGift = false;
                break;
            }
        }
        if (isGift)
        {
            // 若花费没有减少则直接跳过下列步骤, 剪枝, 更快
            if (special[i][specialColSize[i] - 1] > cost)
                continue;
            // 若可以减少费用, 选择大礼包后找寻下一个适合的大礼包
            cost = special[i][specialColSize[i] - 1] + shoppingOffers(price, priceSize, special, specialSize, specialColSize, nowneeds, needsSize);
            if (cost < mincost)
                mincost = cost;
        }
    }
    return mincost;
}
