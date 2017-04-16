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

std::vector<int> plusOneV2(std::vector<int>& digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return digits;
        }
    }
    digits[0] =1;
    digits.push_back(0);
    return digits;
}

int main(int argc, char **argv) {
    int arr1[] = {9, 9, 9, 9, 9, 9};
    std::vector<int> vec1(&arr1[0], &arr1[6]);
    
    //std::vector<int> result = plusOne(vec1);
    std::vector<int> result = plusOneV2(vec1);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}