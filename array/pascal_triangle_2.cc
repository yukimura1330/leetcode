#include <iostream>
#include <vector>
using namespace std;

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> triangle;
    for(int i = 0; i < numRows; i++) {
        std::vector<int> vec(i+1, 0);
        vec[0] = vec[i] = 1;
        for(int j = 1; j < i; j++) {
            vec[j] = triangle[i-1][j-1] + triangle[i-1][j];    
        }
        triangle.push_back(vec);
    }
    return triangle;
}

//vector<vector<int> > generate(int numRows) {
//    vector<vector<int>> r(numRows);
//
//    for (int i = 0; i < numRows; i++) {
//        r[i].resize(i + 1);
//        r[i][0] = r[i][i] = 1;
//
//        for (int j = 1; j < i; j++)
//            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
//    }
//
//    return r;
//}

int main() {
    std::vector<std::vector<int>> triangle;
    triangle = generate(5);
    return 0;
}