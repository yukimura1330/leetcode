/*
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. 
Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array 
and their absolute difference is k.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "gtest/gtest.h"

int findPairs(std::vector<int>& nums, int k) {
    if(k < 0) {
        return 0;
    }

    std::unordered_set<int> starter;
    std::unordered_map<int, int> indices;

    for(int i = 0; i < nums.size(); i++) {
        if(indices.count(nums[i] - k)) {
            starter.insert(nums[i] - k);
        }

        if(indices.count(nums[i] + k)) {
            starter.insert(nums[i]);
        }

        indices[nums[i]] += 1;
    }
    return starter.size();
}

TEST(find_pair, test_pair) {
    int arr1[] = {3,1,4,1,5};
    int arr2[] = {1,2,3,4,5};
    std::vector<int> vec1(&arr1[0], &arr1[5]);
    std::vector<int> vec2(&arr2[0], &arr2[5]);
    
    EXPECT_EQ(2, findPairs(vec1, 2));
    EXPECT_EQ(4, findPairs(vec2, 1));
    EXPECT_EQ(1, findPairs(vec1, 0));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}