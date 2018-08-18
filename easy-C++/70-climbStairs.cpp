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
#include<unordered_map>
using namespace std;

// 2018.7.15

// leetcode 70 . climbStairs ÅÀÂ¥ÌÝ---------> classic DP


// solution : DP
// f(n) = f(n-1) + f(n-2)
// f(1) = 1, f(2) = 2
// use vector
class Solution {
public:
    int climbStairs(int n) {
    	vector<int> dp;
    	dp.push_back(1);
    	dp.push_back(2);
        for (int i = 2; i < n; i ++) {
        	dp.push_back(dp[i-1] + dp[i-2]);
		}
		return dp[n-1];
    }
};

// use C array
class Solution2 {
public:
    int climbStairs(int n) {
    	if (n == 1 || n == 2) return n;
    	int dp[n+1]; // VLA , C syntax
    	dp[1] = 1;
    	dp[2] = 2;
        for (int i = 3; i <= n; i ++) {
        	dp[i] = dp[i-1] + dp[i-2];
		}
		return dp[n];
    }
};  

int main()
{
	int n;
	Solution S;
	while (cin >> n) {
		cout << S.climbStairs(n) << endl;
	}


	return 0;
}

