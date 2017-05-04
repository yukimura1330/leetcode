#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& nums, int r, int c) {
    if(nums.size() <= 0) {
        return nums;
    }
    int row = nums.size();
    int col = nums[0].size();

    if((row * col) != (r * c)) {
        return nums;
    }

    std::vector<std::vector<int>> result(r, std::vector<int>(c, 0));
    for(int i = 0; i < row * col; i++) {
        result[i/c][i%c] = nums[i/col][i%col];
    }
    return result;

    //std::vector<int> allNums;    
    //for(int i = 0; i < row; i++) {
    //    for(int j = 0; j < col; j++) {
    //        allNums.push_back(nums[i][j]);
    //    }
    //}
    //nums.clear();
    //for(int i = 0; i < r; i++) {
    //    std::vector<int> vec;
    //    for(int j = 0; j < c; j++) {
    //        vec.push_back(allNums[i*c+j]);
    //    }
    //    nums.push_back(vec);
    //}
    //return nums;
}