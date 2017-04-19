/*
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] 
and the absolute difference between i and j is at most k.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include "gtest/gtest.h"

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_set<int> oset;
    if (k < 0) {
        return false;
    }
    if (k >= nums.size()) {
        k = nums.size() - 1;
    }
    for(int i = 0; i < nums.size(); i++) {
        if (i > k) {
            oset.erase(nums[i-k-1]);
        }
        if(oset.find(nums[i]) != oset.end()) {
            return true;
        } else {
            oset.insert(nums[i]);
        }
    }
    return false;
}

TEST(stock, bestTimeSell) {
    int arr1[] = {1,0,1,1};
    int arr2[] = {99,99};
    std::vector<int> vec1(&arr1[0], &arr1[4]);
    std::vector<int> vec2(&arr2[0], &arr2[2]);
    EXPECT_EQ(true, containsNearbyDuplicate(vec1, 1));
    EXPECT_EQ(true, containsNearbyDuplicate(vec2, 2));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}