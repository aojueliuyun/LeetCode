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

// 2018.8.4

// leetcode 674 : findLengthOfLCIS / 最长连续递增序列


// solution : 
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxlen = 1, count = 1;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] > nums[i-1]) count ++;
            else count = 1;
            if (count > maxlen) maxlen = count;
        }
        return nums.empty() ? 0 : maxlen;
    }
};

 



int main()
{
    vector<int> test{1,2,6,4,7};
    Solution S;
    cout << S.findLengthOfLCIS(test) << endl;


    return 0;
}

