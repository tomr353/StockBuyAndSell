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
	char	buyIdx, maybeBuyIdx =0;
	char	sellIdx;
	int		price[] = { 5, 5, 5, 2, 4, 6,1,2,3,4,5,6 };
	int		buyPrice, maybeBuyPrice;
	int		sellPrice;
	int		maxProfit;



	buyPrice = price[0];
	maybeBuyPrice = BIGNUM;
	sellPrice = 0;
	buyIdx = sellIdx = 0;
	maxProfit = 0;

	printf("press any key to begin->");
	idx = getchar();

	for (idx = 0; idx < sizeof(price) / sizeof(int); idx++)
	{
		if ((price[idx] < buyPrice) && (price[idx] < maybeBuyPrice))
		{
			maybeBuyPrice = price[idx];
			maybeBuyIdx = idx;
			//debug out 
			printf("maybe...buy[%d] at %d --- sell[%d] at %d --- maybeProfit = %d\n", maybeBuyIdx, maybeBuyPrice, sellIdx, sellPrice, sellPrice-maybeBuyPrice);
		}

		if ((price[idx] > sellPrice) && (sellIdx > buyIdx))
		{
			sellPrice = price[idx];
			sellIdx = idx;

			//new sell price so new MaxProfit
			maxProfit = price[idx] - buyPrice;
			printf("new sell....buy[%d] at %d --- sell[%d] at %d --- profit = %d\n", buyIdx, buyPrice, sellIdx, sellPrice, maxProfit);

		}

		printf("old sell....buy[%d] at %d --- sell[%d] at %d --- profit = %d\n", buyIdx, buyPrice, sellIdx, sellPrice, maxProfit);


		if ((price[idx] - maybeBuyPrice) > maxProfit)
		{
			//set maybe to actual buy
			buyPrice = maybeBuyPrice;
			buyIdx = maybeBuyIdx;
			//set sell to current price/idx
			sellPrice = price[idx];
			sellIdx = idx;
			//set maxProfit to current sell-buy
			maxProfit = sellPrice - buyPrice;
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

