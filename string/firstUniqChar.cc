/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1
s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
*/
#include <iostream>
#include <string>
using namespace std;

int firstUniqChar(string s) {
	int index = 0;
	int bucket[26] = { -1 };
	int len = s.length();
	if(len <= 0) {
		return -1;
	}
	memset(bucket, -1, sizeof(bucket));
	for(int i = 0; i < len; i++) {
		index = s[i] - 'a';
		bucket[index] = bucket[index] + 1;
	}

	for(int i = 0; i < len; i++) {
		index = s[i] - 'a';
		if(bucket[index] == 0) {
			return i;
		}
	}
	return -1;
}

int main() {
	string s1 = "leetcodelodtc";
	string s2 = "loveleetcode";
	std::cout << "s1 firstUniqChar is " << firstUniqChar(s1) << std::endl;
	std::cout << "s2 firstUniqChar is " << firstUniqChar(s2) << std::endl;
	return 0;
}