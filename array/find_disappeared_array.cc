/*
Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/

#include <iostream>
#include <vector>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    int m = 0;
    std::vector<int> result;
    for(int i = 0; i < nums.size(); i++) {
        m = abs(nums[i]) - 1;
        nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) {
            result.push_back(i+1);
        }
    }
    return result;
}

void printVec(std::vector<int>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr1[] = {4,3,2,7,8,2,3,1};
    std::vector<int> vec1(&arr1[0], &arr1[8]);
    std::vector<int> result;

    result = findDisappearedNumbers(vec1);
    printVec(result);
    return 0;
}