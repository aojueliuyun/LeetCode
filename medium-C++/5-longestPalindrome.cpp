#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<cctype>
#include<numeric>
#include<bitset>
#include<unordered_map>
using namespace std;

// 2018.7.27

// leetcode 5 : longestPalindrome / 最长回文子串


// solution 1 : use xor and traverse  || not so elegant
class Solution {
public:
    string longestPalindrome(string s) {
    	if (s.length() <= 1)
			return s;
    	pair<int, int> curMax{0,-1};
        for (int i = 0; i < s.length(); i ++) {
        	int res = 0;
        	int l = i, r = i+1; // the case like : abcba
        	while (l >= 0 && r < s.length()) {
        		res = res ^ (s[l] ^ s[r]);
        		if (res == 0) {
        			if (r-l > curMax.second-curMax.first)
        				curMax = {l, r};
        			l --;
        			r ++;
				}
				else break;
			}
			l = i-1; // the case like : abba
			r = i+1;
			res = 0;
			if (curMax.second - curMax.first <= 0) {
				curMax = {i, i};
			}
			while (l >= 0 && r < s.length()) {
				res = res ^ (s[l] ^ s[r]);
        		if (res == 0) {
        			if (r-l > curMax.second-curMax.first)
        				curMax = {l, r};
        			l --;
        			r ++;
				}
				else break;
			}
		}
		string res = s.substr(curMax.first, curMax.second - curMax.first + 1);
		return res;
    }
};



// solution 2 : from daolaos, can not understand
class Solution2 {
public:
    string longestPalindrome(string s) {
        int len = (int) s.length();
        int left = 0;
        int right = 0;
        int leftres = 0;
        int maxlen = 0;

        int i = 0;
        while (i < len) {
            left = i;
            right = i;
            while (right + 1 < len && s[right] == s[right + 1]) ++right;
            i=right+1;
            while (left >= 0 && right < len && s[left] == s[right]) {
                --left;
                ++right;
            }
            if (maxlen < right - left - 1) {
                leftres = left + 1;
                maxlen = right - left - 1;
            }
        }
        return s.substr(leftres, maxlen);
    }
};


// solution 3 : use == to judge
class Solution3 {
public:
    static string longestPalindrome(string s) {
        int len = s.length();
        int left = 0;
        int right = 0;
        int leftres = 0;
        int maxlen = 0;
        for (int i = 0; i < len; i ++) {
        	left = right = i;
        	while (right + 1 < len && s[right + 1] == s[right]) {
        		right ++;
			}
        	while (left >= 0 && right < len && s[left] == s[right]) {
        		left --;
        		right ++;
			}
			if (maxlen < right - left - 1) {
				leftres = left + 1;
				maxlen = right - left - 1;
			}
		}
        return s.substr(leftres, maxlen);
    }
};


int main()
{

	string s;
	Solution3 S;
	while (cin >> s) {
		cout << S.longestPalindrome(s) << endl;
	}

	return 0;
}

