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

// 2018.7.26

// leetcode 208 : minSubArrayLen


// solution : two pointers
// time : O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = nums.size() + 1, sum = 0;
        int i, j;
        for (i = 0, j = 0; i < nums.size(); ) {
            if (sum < s) sum += nums[i ++];
            else {
                res = min(res, i-j);
                sum -= nums[j++];
            }
        }
        for (; j < nums.size(); j ++) {
            if (sum < s) break;
            else {
                res = min(res, i-j);
                sum -= nums[j];
            }
        }
        return res == nums.size() + 1 ? 0 : res;
    }
};



int main()
{
    vector<int> test{2,3,1,2,4,3};
    Solution S;
    cout << S.minSubArrayLen(7, test) << endl;


	return 0;
}

