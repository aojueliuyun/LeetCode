#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<cctype>
#include<unordered_map>
using namespace std;

// 2018.7.17
// leetcode 125 : isPalindrome 验证回文字符串 


// solution : just use two pointers ---------> Life is short, STL is good!
// time: O(n)

class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0, tail = s.length()-1;
        while (head < tail) {
        	while (!isalnum(s[head]) && head < s.length()) head ++;
        	while (!isalnum(s[tail]) && tail >= 0) tail --;
        	if (tolower(s[head++]) == tolower(s[tail--])) continue;
        	else return false;
		}
		return true;
    }
};

int main()
{
	string s;
	Solution S;
	while (cin >> s) {
		cout << S.isPalindrome(s) << endl;
	}

	return 0;
}

