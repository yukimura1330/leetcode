/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票
*/
#include <iostream>
#include <vector>
using namespace std;
/*
//用时最少解答
int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    int profit = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
        if (prices[i + 1] > prices[i]) {
            profit += prices[i + 1] - prices[i];
        }
    }
    return profit;
}
*/

int maxProfit(vector<int>& prices) {
	int i = 0, j = 0;
    int result = 0;
    int maxProfit = 0;
    if(prices.size() < 2) {
    	return 0;
    }
        
    for(i = 1; i < prices.size(); i++) {
        if(prices[i] > prices[i-1]) {
        	maxProfit = prices[i] - prices[i-1];
            for(j = i+1; j < prices.size(); j++) {
                if(prices[j] > prices[j-1]) {
                    maxProfit = max(maxProfit, prices[j] - prices[i-1]);
                } else {
                    break;
                }
            }
            i = j;
            result += maxProfit;   
        }
    }
    return result;
}

int main() {
	vector<int> vec1 = {7, 1, 5, 3, 6, 4};
	vector<int> vec2 = {1, 2, 3, 4, 5};
	vector<int> vec3 = {2,1,4};
	vector<int> vec4 = {1,2,7,4,11};
	vector<int> vec5 = {1, 2};
	cout << "vec1 maxProfit = " << maxProfit(vec1) << endl;
	cout << "vec2 maxProfit = " << maxProfit(vec2) << endl;
	cout << "vec3 maxProfit = " << maxProfit(vec3) << endl;
	cout << "vec4 maxProfit = " << maxProfit(vec4) << endl;
	cout << "vec5 maxProfit = " << maxProfit(vec5) << endl;	
	return 0;
}
