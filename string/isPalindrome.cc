/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
输入: "A man, a plan, a canal: Panama"
输出: true
输入: "race a car"
输出: false
*/
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int len = s.length();
    if(len <= 0) {
        return true;
    }
    int startIdx = 0;
    int endIdx = len;
    while(startIdx < endIdx) {          
        if(!isalnum(s[startIdx])) {
            startIdx++;
            continue;
        }
        if(!isalnum(s[endIdx])) {
            endIdx--;
            continue;
        }
        
        if (isupper(s[startIdx])) {
           s[startIdx] = tolower(s[startIdx]); 
        }
        if (isupper(s[endIdx])) {
           s[endIdx] = tolower(s[endIdx]); 
        }            
        
        if(s[startIdx] != s[endIdx]) {
            return false;
        }
        startIdx++;
        endIdx--;
    }
    return true;
}

int main() {
    string s1 = "A man, a plan, a canal: Panama";
    cout << "isPalindrome is " << isPalindrome(s1) << endl;
    return 0;
}