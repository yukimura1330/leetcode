/*
给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool myCompare(int i, int j) {return (i<j);}
bool containsDuplicate(vector<int>& nums) {
    if(nums.size() < 2) {
        return false;
    }
    std::sort(nums.begin(), nums.end(), myCompare);
    for(int i = 0; i < nums.size() - 1; i++) {
        if(nums[i+1] == nums[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> vec1 = {1, 2, 3, 1};
    std::vector<int> vec2 = {1, 2, 3, 4};
    std::vector<int> vec3 = {1, 1, 2, 2, 3, 4};

    std::cout << "vec1 is " << containsDuplicate(vec1) << std::endl;
    std::cout << "vec2 is " << containsDuplicate(vec2) << std::endl;
    std::cout << "vec3 is " << containsDuplicate(vec3) << std::endl;
    return 0;
}
