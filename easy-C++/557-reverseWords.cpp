#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cmath>
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

// 2018.7.29

// leetcode 557 : reverseWords /  反转字符串中的单词 III


// solution : use string::find()
class Solution {
public:
    string reverseWords(string s) {
    	int pos = s.find(' ', 0), start = 0;
        while (pos != string::npos) {
        	for (int i = start, j = pos-1; i < j; i ++, j --) {
        		swap(s[i], s[j]);
			}
			start = pos+1;
        	pos = s.find(' ', start);
		}
		for (int i = start, j = s.length()-1; i < j; i ++, j --) swap(s[i], s[j]); // reverse the last word
		return s;
    }
};


// solution 2 : use std::reverse(), do not use string::find() --------> simplier
class Solution2 {
public:
    string reverseWords(string s) {
    	int t = 0;
    	for (int i = 0; i < s.length(); i ++) {
    		if (s[i] == ' ') {
    			reverse(s.begin()+t, s.begin()+i);
    			t = i+1;
			}
		}
		reverse(s.begin()+t, s.end()); // reverse the last word
		return s;
    }
};



int main()
{



	return 0;
}

