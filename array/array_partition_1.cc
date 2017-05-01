/*

Given an array of 2n integers, your task is to group these integers into n pairs of integer, 
say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
Example 1:
Input: [1,4,3,2]
Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4.

这道题让我们分割数组，两两一对，让每对中较小的数的和最大。这题难度不大，用贪婪算法就可以了。
由于我们要最大化每对中的较小值之和，那么肯定是每对中两个数字大小越接近越好，
因为如果差距过大，而我们只取较小的数字，那么大数字就浪费掉了。明白了这一点，
我们只需要给数组排个序，然后按顺序的每两个就是一对，我们取出每对中的第一个数即为较小值累加起来即可
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"

int arrayPairSum(std::vector<int>& nums) {
    int result = 0;
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i += 2) {
        result += nums[i];
    }
    return result;
}

TEST(arrayPairSum, test_pair_sum) {
    int arr1[] = {1,2,3,2};
    int arr2[] = {2,5,6,7,8,9};
    int arr3[] = {2,1,4,3};
    std::vector<int> vec1(&arr1[0], &arr1[4]);
    std::vector<int> vec2(&arr2[0], &arr2[6]);
    std::vector<int> vec3(&arr3[0], &arr3[4]);

    EXPECT_EQ(3, arrayPairSum(vec1));
    EXPECT_EQ(16, arrayPairSum(vec2));
    EXPECT_EQ(4, arrayPairSum(vec3));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}