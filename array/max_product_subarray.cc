/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#define MAX(a,b) ((a) < (b) ? (b) : (a))
#define MIN(a,b) ((a) > (b) ? (b) : (a))
int maxProduct(std::vector<int>& nums) {
    #define MAX(a,b) ((a) < (b) ? (b) : (a))
    #define MIN(a,b) ((a) > (b) ? (b) : (a))
    if(nums.size() <= 0) {
        return 0;
    }
    int result = nums[0];
    int max_product = nums[0];
    int min_product = nums[0];
    int max_temp = nums[0];
    int min_temp = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        max_temp = max_product * nums[i];
        min_temp = min_product * nums[i];
        max_product = MAX(MAX(max_temp, nums[i]), min_temp);
        min_product = MIN(MIN(max_temp, nums[i]), min_temp);

        result = MAX(result, max_product);
    }
    return result;
}

TEST(maxProduct, test_max_product) {
    int arr1[] = {2,3,-2,4};
    int arr2[] = {1,0,2,-2,2};
    int arr3[] = {-1,-2,-9,-6};
    std::vector<int> vec1(&arr1[0], &arr1[4]);
    std::vector<int> vec2(&arr2[0], &arr2[5]);
    std::vector<int> vec3(&arr3[0], &arr3[4]);
    EXPECT_EQ(6, maxProduct(vec1));
    EXPECT_EQ(2, maxProduct(vec2));
    EXPECT_EQ(108, maxProduct(vec3));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}