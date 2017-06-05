// StockBuyAndSell.cpp : Defines the entry point for the console application.
//

// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

#define		BIGNUM	99999

int main()
{
	char	idx;
	char	buyIdx, maybeBuyIdx;
	char	sellIdx;
	int		price[] = { 5, 5, 5, 4, 4, 6 };
	int		buyPrice, maybeBuyPrice;
	int		sellPrice;
	int		maxProfit;

	buyPrice = price[0];
	maybeBuyPrice = BIGNUM;
	sellPrice = 0;
	buyIdx = sellIdx = 0;
	maxProfit = price[sellIdx] - price[buyIdx];

	printf("press any key to begin->");
	idx = getchar();

	for (idx = 0; idx < sizeof(price) / sizeof(int); idx++)
	{
		if (price[idx] < buyPrice)
		{
			maybeBuyPrice = price[idx];
			maybeBuyIdx = idx;
			//debug out 
			printf("maybe...buy[%d] at %d --- sell[%d] at %d --- profit = %d\n", maybeBuyIdx, maybeBuyPrice, sellIdx, sellPrice, maxProfit);
		}

		if (price[idx] > sellPrice)
		{
			sellPrice = price[idx];
			sellIdx = idx;

			//new sell price so new MaxProfit
			maxProfit = price[idx] - buyPrice;
			printf("new sell....buy[%d] at %d --- sell[%d] at %d --- profit = %d\n", buyIdx, buyPrice, sellIdx, sellPrice, maxProfit);

		}

		if ((price[idx] - maybeBuyPrice) > maxProfit)
		{
			//set maybe to actual buy
			buyPrice = maybeBuyPrice;
			buyIdx = maybeBuyIdx;
			//set sell to current price/idx
			sellPrice = price[idx];
			sellIdx = idx;
			//set maxProfit to current sell-buy
			maxProfit = price[idx] - buyPrice;
			//new buy/sell combo so print new data
			printf("new sell....buy[%d] at %d --- sell[%d] at %d --- profit = %d\n", buyIdx, buyPrice, sellIdx, sellPrice, maxProfit);
		}

	}
	maxProfit = sellPrice - buyPrice;
	//print out the results
	printf("final result:  buy[%d] at %d --- sell[%d] at %d --- profit = %d\n", buyIdx, buyPrice, sellIdx, sellPrice, maxProfit);
	//hold screen for any char
	idx = getchar();
	idx = getchar();

	return 0;
}

