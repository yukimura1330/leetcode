#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    std::vector<int> nums;
    if(n == 0) {
        return; 
    }
    if(m == 0) {
        nums1.clear();
        nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
        return;
    }
    int i = 0;
    int j = 0;

    while(i < m && j < n) {
        if(nums1[i] > nums2[j]) {
            nums.push_back(nums2[j]);
            j++;
        } else {
            nums.push_back(nums1[i]);
            i++;
        }
    }

    while(i < m) {
        nums.push_back(nums1[i]);
        i++;
    }

    while(j < n) {
        nums.push_back(nums2[j]);
        j++;
    }

    nums1.clear();
    nums1.insert(nums1.begin(), nums.begin(), nums.end());
}

void printVec(std::vector<int>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr1[] = {1, 2, 3, 0, 0, 0};
    int arr2[] = {2,5,6};
    std::vector<int> vec1(&arr1[0], &arr1[6]);
    std::vector<int> vec2(&arr2[0], &arr2[3]);

    merge(vec1, 3, vec2, 3);
    printVec(vec1);
    return 0;
}