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

// 2018.8.17

// leetcode 746 : minCostClimbingStairs / 使用最小花费爬楼梯


// solution : DP :   dp[n] = min(dp(n-1) + cost[n-1], dp(n-2) + cost[n-2])
//                   dp(0) = 0, dp[1] = 0
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0);
        for (int i = 2; i < dp.size(); i ++) {
        	dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
		}
		return dp.back();
    }
};


int main()
{
	Solution S;
	vector<int> test{0,1,2,0};
	cout << S.minCostClimbingStairs(test) << endl;

	return 0;
}

