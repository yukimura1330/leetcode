/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
 */
#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    if(size <= 1) {
        return;
    }
    k = k % size;
    if(k == 0) {
        return;
    }

    for(int i = 0, j = size - 1; i < j; i++, j--) {
        swap(nums[i], nums[j]);
    }

    for(int i = 0, j = k - 1; i < j; i++, j--) {
       swap(nums[i], nums[j]);
    }

    for(int i = k, j = size - 1; i < j; i++, j--) {
       swap(nums[i], nums[j]);
    }
    return;
}

int main() {
	vector<int> vec = {1,2,3,4,5,6,7};
	cout << "befor rotate: ";
	for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	rotate(vec, 7);
	cout << "after rotate: ";
	for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}