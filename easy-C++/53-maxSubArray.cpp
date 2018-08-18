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

// ;eetcode 53 : maxSubArray 最大子序列和, 注意这里要求子数组最少包含一个元素 

// Solution 1
// time: O(n)
// spave: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = nums[0];
        for (int i = 0; i < nums.size(); i ++) {
        	if (sum >= 0) sum += nums[i];
        	else sum = nums[i];       // if subarray could have 0 element then sum = 0 
        	// two lines above can be replaced by -------> sum = max(sum + nums[i], nums[i]);
        	if(sum > maxSum) maxSum = sum;
		}
		return maxSum;
    }
}; 



// solution 2 : DP ------------>  same as solution 1, just different writing
// time: O(n)
// space: O(n)
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i ++) {
            dp[i] = max(dp[i], dp[i-1] + dp[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


// solution 3 : divide and conquer ---------------- >  later
// time: O(nlogn)
// space: 
class Solution3 {
public:
    int maxSubArray(vector<int>& nums) {
        
    }
};



int main()
{



	return 0;
}

