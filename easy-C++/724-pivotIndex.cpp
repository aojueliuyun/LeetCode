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

// 2018.8.14

// leetcdoe 724 : pivotIndex


// solution 1 : get the sum array
// time : O(n)
// space : O(n)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sum;
        int cur = 0;
        for (auto x : nums) {
            cur += x;
            sum.push_back(cur);
        }
        for (int i = 0; i < sum.size(); i ++) {
            int tmp = 0;
            if (i == 0) tmp = 0;
            else tmp = sum[i-1];
            if (tmp * 2 == sum.back() - nums[i]) return i;
        }
        return -1;
    }
};


// solution 2 : get sum of all elements and traverse from left to right
// time : O(n)
// space: O(1)
class Solution2 {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        int rsum = accumulate(nums.begin(), nums.end(), 0); // in <numeric>
        int lsum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (lsum == rsum - nums[i])
                return i;
            else {
                lsum += nums[i];
                rsum -= nums[i];
            }
        }
        return -1;
    }
};



int main()
{
    vector<int> vec{1, 7, 3, 6, 5, 6};
    Solution2 S;
    cout << S.pivotIndex(vec) << endl;



    return 0;
}

