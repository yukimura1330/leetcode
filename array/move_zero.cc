#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    if(nums.size() <= 1) {
        return;
    }
    int first = 0;
    int temp = 0;
    for(int next = first + 1; next < nums.size(); next++) {
        if(nums[first] != 0) {
            first++;
        }
        if(nums[first] == 0 && nums[next] != 0) {
            temp = nums[first];
            nums[first] = nums[next];
            nums[next] = temp;
            first++;
        }
    }
    return;
}

void printVec(std::vector<int>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    int arr1[] = {0, 1, 0, 3, 12};
    std::vector<int> vec1(&arr1[0], &arr1[5]);

    printVec(vec1);
    moveZeroes(vec1);
    printVec(vec1);
    return 0;
}