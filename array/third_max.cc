/*
Given a non-empty array of integers, return the third maximum number in this array. 
If it does not exist, return the maximum number. The time complexity must be in O(n).
*/
#include <iostream>
#include <vector>
#include <set>
#include "gtest/gtest.h"

int thirdMax(std::vector<int>& nums) {
    std::set<int> top3;
    for(int i = 0; i < nums.size(); i++) {
        top3.insert(nums[i]);
        if(top3.size() > 3) {
            top3.erase(top3.begin());
        }
    }
    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}

TEST(thirdMax, test_thrid_max) {
    int arr1[] = {3,2,1};
    int arr2[] = {3,2,2,2,2};
    int arr3[] = {2,1};
    int arr4[] = {3,5,6,7,2,8,9};
    int arr5[] = {1,2,3};
    int arr6[] = {1, INT_MIN, 2};
    int arr7[] = {2};
    std::vector<int> vec1(&arr1[0], &arr1[3]);
    std::vector<int> vec2(&arr2[0], &arr2[5]);
    std::vector<int> vec3(&arr3[0], &arr3[2]);
    std::vector<int> vec4(&arr4[0], &arr4[7]);
    std::vector<int> vec5(&arr5[0], &arr5[3]);
    std::vector<int> vec6(&arr6[0], &arr6[3]);
    std::vector<int> vec7(&arr7[0], &arr7[1]);
    EXPECT_EQ(1, thirdMax(vec1));
    EXPECT_EQ(3, thirdMax(vec2));
    EXPECT_EQ(2, thirdMax(vec3));
    EXPECT_EQ(7, thirdMax(vec4));
    EXPECT_EQ(1, thirdMax(vec5));
    EXPECT_EQ(INT_MIN, thirdMax(vec6));
    EXPECT_EQ(2, thirdMax(vec7));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}