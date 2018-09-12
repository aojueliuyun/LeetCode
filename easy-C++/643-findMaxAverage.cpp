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

// 2018.8.3

// leetcode 643 : findMaxAverage 


// solution 1 : maintain a sum of k values
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, maxsum = -1e200;
        for (int i = 0; i < k; i ++) {
            sum += nums[i];
        }
        maxsum = sum;
        for (int i = k; i < nums.size(); i ++) {
            sum += nums[i] - nums[i-k];
            if (sum > maxsum) maxsum = sum;
        }
        return maxsum / k;
    }
};



int main()
{
    vector<int> nums{-1};
    Solution S;
    cout << S.findMaxAverage(nums, 1) << endl;


    return 0;
}

