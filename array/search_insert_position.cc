/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
	int pos = 0;
	for(int i = 0; i < nums.size(); i++) {
		if (target <= nums[i]) {
			pos = i;
			break;
		} else {
			pos = i+1;
		}
	}
	return pos;
}

// int searchInsert(std::vector<int>& nums, int target) {
// 	int low = 0;
// 	int height = nums.size() - 1;
// 	int mid = 0;
// 	while(low <= height) {
// 		mid = low + (height - low)/2;
// 		if (nums[mid] > target) {
// 			height = mid - 1;
// 		} else {
// 			low = mid + 1;
// 		}
// 	}
// 	return low;
// }

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	int result = searchInsert(vec, 2);
	std::cout << "result is " << result << std::endl;

	return 0;
}