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
#include<bitset>
#include<unordered_map>
using namespace std;

// 2018.7.26

// leetcode 453 : minMoves / 最少移动次数


// solution : add n-1 min elements by 1, equals substract max elemnt by 1, in other way
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minval = nums[0], sum = 0, n = nums.size();
        for (auto x : nums) {
            if (x < minval)
                minval = x;
            sum += x;
        }
        return sum - minval * n;
    }
};


int main()
{



    return 0;
}

