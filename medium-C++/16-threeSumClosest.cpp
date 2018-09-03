#include<iostream>
#include<fstream>
#include<sstream>
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

// 2018.8.30

// leetcode 16 : threeSumClosest


// solution : double pointer just like problem 15
// time : O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i ++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = nums.size()-1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > target) {
                    r --;
                }
                else if (sum < target) {
                    l ++;
                }
                else return target;
                if (abs(res - target) > abs(sum - target)) res = sum;
            }
        }
        return res;
    }
};


int main()
{
    vector<int> test{1,2};
    Solution S;
    cout << S.threeSumClosest(test, 3) << endl;

	return 0;
}

