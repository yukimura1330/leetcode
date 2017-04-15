/*
Say you have an array for which the i th element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
*/

#include <iostream>
#include <vector>
#include "gtest/gtest.h"

int maxProfit(std::vector<int>& prices) {
    if (prices.size() <= 0) {
        return 0;
    }
    int max_profit = 0;
    int min = prices[0], max = 0;
    for(int i = 0; i < prices.size() - 1; i++) {
        if (prices[i+1] > prices[i]) {
            max = prices[i+1] > max ? prices[i+1] : max;
            min = prices[i] < min ? prices[i] : min;
            max_profit = (max - min) > max_profit ? (max - min) : max_profit;         
        } else {
            min = prices[i+1] < min ? prices[i+1] : min;
            max = 0;
        }  
    }
    return max_profit;
}

TEST(stock, bestTimeSell) {
    int arr1[] = {7, 1, 5, 8, 6, 4};
    int arr2[] = {2, 1, 2, 0, 1};
    int arr3[] = {7, 6, 4, 3, 1};
    std::vector<int> vec1(&arr1[0], &arr1[6]);
    std::vector<int> vec2(&arr2[0], &arr2[5]);
    std::vector<int> vec3(&arr3[0], &arr3[5]);
    EXPECT_EQ(7, maxProfit(vec1));
    EXPECT_EQ(1, maxProfit(vec2));
    EXPECT_EQ(0, maxProfit(vec3));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}