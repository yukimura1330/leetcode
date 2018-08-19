/*
给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。
说明：
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像 
*/
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int temp = 0;
    int size = matrix.size();
    if(size <= 0) {
        return;
    }
    
    for(int i = 0; i < size/2; i++) {
        for(int j = i; j < size - 1 - i; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[size - 1 -j][i]; 
            matrix[size - 1 -j][i] = matrix[size - 1 - i][size - 1 -j];
            matrix[size - 1 - i][size - 1 -j] = matrix[j][size - 1 - i];
            matrix[j][size - 1 - i] = temp;
        }
    }
}
//沿着对角线翻转后，每一行进行反转
void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
        reverse(matrix[i].begin(), matrix[i].end());
    }
}	
int main() {
	vector<vector<int>> matrix = {{1,2,3,4},
	                              {5,6,7,8},
	                              {9,10,11,12},
	                              {13,14,15,16}};
	rotate(matrix);
	return 0;
}