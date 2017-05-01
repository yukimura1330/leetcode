/*
Given an array of integers that is already sorted in ascending order,
find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::vector<int> result;
    int start = 0, end = numbers.size()-1;
    int mid = 0;
    while(numbers[start] + numbers[end] != target) {
        if (numbers[start] + numbers[end] < target) {
            start++;
        } else {
            end--;
        }
    }
    result.push_back(start+1);
    result.push_back(end+1);
    return result;
}

void printVec(std::vector<int>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr1[] = {2, 7, 11, 15};
    std::vector<int> vec1(&arr1[0], &arr1[3]);
    std::vector<int> result;

    result = twoSum(vec1, 9);
    printVec(result);
    return 0;
}