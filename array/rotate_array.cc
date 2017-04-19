#include <iostream>
#include <vector>

void rotate(std::vector<int>& nums, int k) {
    int oldSize = nums.size();
    k = k % nums.size();
    if(k == 0) {
        return;
    }
    nums.resize(oldSize+k);
    for(int i = oldSize-1; i >= 0; --i) {
        nums[i+k] = nums[i];
    }

    for(int i = 0; i < k; i++) {
        nums[i] = nums[oldSize+i];
    }
    nums.resize(oldSize);
}

int main() {
    int a[] = {1,2,3,4,5,6};
    std::vector<int> arr(&a[0], &a[6]);
    rotate(arr, 2);
    return 0;
}