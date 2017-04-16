/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
The digits are stored such that the most significant digit is at the head of the list.
*/

#include <iostream>
#include <vector>
#include <stack>

std::vector<int> plusOne(std::vector<int>& digits) {
    std::stack<int> stack1;
    int flag = 1;
    for(int i  = digits.size() - 1; i >= 0; i--) {
        digits[i] += flag;
        flag = digits[i] / 10;
        if (digits[i] / 10 > 0) {
            digits[i] = digits[i] % 10;
        }
        stack1.push(digits[i]);
    }

    if (flag > 0) {
        stack1.push(flag);
    }
    digits.clear();
    while(!stack1.empty()) {
        digits.push_back(stack1.top());
        stack1.pop();
    }
    return digits;
}

int main(int argc, char **argv) {
    int arr1[] = {9, 9, 9, 9, 9, 9};
    int arr2[] = {9};
    int arr3[] = {1, 0};
    std::vector<int> vec1(&arr1[0], &arr1[6]);
    std::vector<int> vec2(&arr2[0], &arr2[1]);
    std::vector<int> vec3(&arr3[0], &arr3[2]);
    
    std::vector<int> result = plusOne(vec1);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}