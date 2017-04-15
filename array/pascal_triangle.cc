/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<int> getRow(int rowIndex) {
	std::vector<int> result(rowIndex+1, 0);
	result[0] = 1;
	for(int i = 1; i < rowIndex + 1; i++) {
		for(int j = i; j >= 1; j--) {
			result[j] += result[j-1];
		}
	}
	return result;
}

int main() {
	std::vector<int> vec = getRow(3);

	for(int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}