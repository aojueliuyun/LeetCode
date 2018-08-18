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
#include<unordered_map>
using namespace std;

// 2018.7.23

// leetcode 242 isAnagram / ÅÐ¶ÏÁ½¸ö×Ö·û´®ÊÇ·ñÊÇ×ÖÄ¸ÒìÎ»´Ê


// solution 1 : use vector / C array / hash map  || two maps or one map all alright
// time: O(n)      n is max length of s and t
// space: O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ms, mt;
        for (auto c : s) ms[c] ++;
		for (auto c : t) mt[c] ++;
		for (auto x : ms) {
			if (x.second != mt[x.first]) return false;
			mt.erase(x.first);
		}
		if (mt.empty()) return true;
		return false;
    }
}; 


// solution 2 : use bit operation -> xor and multiply
// time: O(n)
// space: O(1)
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        int ret = 0, stimes = 1, ttimes = 1;
        for (auto c : s) {
        	ret ^= c;
        	stimes *= c;
		}
		for (auto c : t) {
			ret ^= c;
			ttimes *= c;
		}
		return ret == 0 && stimes == ttimes;
    }
};

// solution 3 : sort and compare----------> not efficient
// time: O(nlogn)
// space: O(1)
class Solution3 {
public:
    bool isAnagram(string s, string t) {
    	if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i=0; i < s.length(); i ++) {
        	if (s[i] != t[i]) return false;
		}
		return true;
    }
};


int main()
{



	return 0;
}

