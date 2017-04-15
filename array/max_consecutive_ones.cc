/* Given a binary array, find the maximum number of consecutive 1s in this array.
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.
*/
#include <iostream>
#include <vector>
#include "gtest/gtest.h"

int findMaxConsecutiveOnes(std::vector<int>& nums) {
	int maxLen = 0, len = 0;

	for(int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			len += 1;
			if(len > maxLen) {
				maxLen = len;
			}
		} else {
			len = 0;
		}
	}
	return maxLen;
}

TEST(firstTest, findMaxOnesLen) {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(1);
	EXPECT_EQ(3, findMaxConsecutiveOnes(vec));
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}