/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
输入: s = "anagram", t = "nagaram"
输出: true
输入: s = "rat", t = "car"
输出: false
*/
#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    int index = 0;
    int bucket[26];
    int len1 = s.length();
    int len2 = t.length();
    
    if(len1 != len2) {
        return false;
    }
    memset(bucket, 0, sizeof(bucket));
    for(int i = 0; i < len1; i++) {
        index = s[i] - 'a';
        bucket[index] += 1;

        index = t[i] - 'a';
        bucket[index] -= 1;
    }
    
    for(int i = 0; i < 26; i++) {
        if(bucket[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1 = "rat";
    string s2 = "cat";

    cout << "isAnagram is " << isAnagram(s1, s2) << endl;
    return 0;
}