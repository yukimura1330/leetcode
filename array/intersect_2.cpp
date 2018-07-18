/*
两个数组的交集II
给定两个数组，写一个方法来计算它们的交集。
例如:
给定 nums1 = [1, 2, 2, 1], nums2 = [2, 2], 返回 [2, 2].
注意：
   输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
   我们可以不考虑输出结果的顺序。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int> result;
	int pos = 0;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	for(int i = 0; i < nums1.size(); i++) {
		for(int j = pos; j < nums2.size(); j++) {
			if(nums1[i] == nums2[j]) {
				result.push_back(nums1[i]);
				pos = j+1;
				break;
			}
		}
	}

	// for(int i = 0; i < result.size(); i++) {
	// 	cout << result[i] << " ";
	// }
	// cout << endl;
	return result;
}

int main() {
	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 2};
	vector<int> nums3 = {1, 2};
	vector<int> nums4 = {4};

	intersect(nums1, nums2);
	intersect(nums1, nums3);
	intersect(nums2, nums3);
	intersect(nums4, nums3);
	return 0;
}
