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

// 2018.7.21

// leetcode 198 : house robber ´ò¼Ò½ÙÉá --------------> Simple DP


// the key of DP :     recurrence equation, and boundary codition

// solution :     DP : f(n) = max{f(n-1), f(n-2) + A[n]}, started with f(1) = A[1], f(1) = max{f(1), A[1]}
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp{nums[0], max(nums[0], nums[1])}; // initialize with two values
        for (int i=2; i < nums.size(); i++) {
            dp.push_back(max(dp[i-1], dp[i-2] + nums[i]));
        }
        return *(dp.end()-1);
    }
};


int main()
{



    return 0;
}

