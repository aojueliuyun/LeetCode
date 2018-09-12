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

// leetcode 665 : checkPossibility


// solution : 
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size() && count <= 1; i ++) {
            if (nums[i-1] > nums[i]) {
                count ++;
                if (i-2 < 0 || nums[i-2] <= nums[i]) {
                    nums[i-1] = nums[i];
                }
                else nums[i] = nums[i-1];
            }
        }
        return count <= 1;
    }
};



int main()
{



    return 0;
}

