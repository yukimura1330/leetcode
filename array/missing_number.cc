/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
For example,
Given nums = [0, 1, 3] return 2.
*/

#include <vector>
#include <iostream>

int missingNumber(std::vector<int>& nums) {
	int result = 0;
	std::vector<int> vec(nums.size() + 1, 0);
	for(int i = 0; i < nums.size(); i++) {
		vec[nums[i]] = 1;
	}

	for(int i = 0; i < vec.size(); i++) {
		if(vec[i] != 1) {
			result = i;
		}
	}
	return result;
}

int missingNumber_v2(std::vector<int>& nums) {
	int result = nums.size();
	for(int i = 0; i < nums.size(); i++) {
		result ^= nums[i];
		result ^= i;
	}
	return result;
}

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(0);
	std::cout << "the missing number is " << missingNumber(vec) << std::endl;
	return 0;
}