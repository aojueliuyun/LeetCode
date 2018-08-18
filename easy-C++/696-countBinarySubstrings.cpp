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
#include<unordered_set>
using namespace std;

// 2018.8.13

// leetcode 696 : countBinarySubstrings / 计数二进制子串


// solution -1 : brute-force 
// result: ----------------> TLE---------> Read the description carefully !!!
class Solution_1 {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i ++) {
        	for (int j = 2; i+j <= s.length(); j += 2) {
        		string tmp = s.substr(i, j);
        		if (isSame01(tmp) && isContinuous01(tmp)) {
        			ans ++;
				}
			}
		}
		return ans;
    }
    bool isSame01(const string & str) {
    	unordered_map<char, int> record;
    	for (auto x : str) {
    		record[x] ++;
		}
		return record['0'] == record['1'];
	}
	bool isContinuous01(const string & str) {
		char ch = str[0];
		for (int i = 1; i < str.length()/2; i ++) {
			if (ch != str[i]) return false;
		}
		ch = ch=='0' ? '1' : '0';
		for (int i = str.length()/2; i < str.length(); i ++) {
			if (ch != str[i]) return false;
		}
		return true;
	}
};



// solution 1 : use a vector
// time: O(n)
// space: O(k)
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> record;
        char ch = s[0];
        int count = 1;
        for (int i = 1; i < s.length(); i ++) {
        	if (s[i] == ch) count ++;
        	else {
        		ch = s[i];
        		record.push_back(count);
        		count = 1;
			}
		}
		record.push_back(count);
		int res = 0;
 		for (int i = 0; i < record.size()-1; i ++) {
			res += min(record[i], record[i+1]);
		}
		return res; 
	}
};



int main()
{
	string s;
	Solution S;
	while (cin >> s) {
		cout << S.countBinarySubstrings(s) << endl;
	}


	return 0;
}

