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


// 2018.7.28

// leetcode 459 repeatedSubstringPattern : judge whether a string is constructed by it's substring repeating many times 


// solution 1 : brute-force attack || traverse all cases
// time : worst O(n^2)  average O(n) ? --> don't know
// space : O(1)
// execution time : 28ms
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
    	bool flag = false;
        for (int i = 1; i <= s.length()/2; i ++) {
        	if (s.length() % i != 0) continue;
        	else {
        		string repeat = s.substr(0,i);
        		for (int j = i; j < s.length(); j +=i) {
        			if (s.substr(j, i) == repeat) {
        				flag = true;
					}
					else {
						flag = false;
						break;
					}
				}
				if (flag) return true;
			}
		}
		return false;
    }
};


// solution 2 : DP || In fact, it is KMP. -------> time to reivew KMP 
// time : O(n)
// space : O(n)
class Solution2 {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 1, j = 0, n = s.size();
        vector<int> dp(n+1, 0);
        while(i < n){
            if(s[i] == s[j]) dp[++i] = ++j;
            else if (j == 0) ++i;
            else j = dp[j];
        }
        return dp[n] && (dp[n] % (n-dp[n]) == 0);
    }
};



int main()
{
	string s;
	Solution S;
	while (cin >> s) {
		cout << S.repeatedSubstringPattern(s) << endl;
	}


	return 0;
}

