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

// leetcode 747 : dominantIndex 


// solution : one round traverse to record the indexs of first and second max numbers
// time: O(n)
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first = 0, second = -1;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] >= nums[first]) {
                second = first;
                first = i;
            }
            else if (second == -1 || nums[i] > nums[second]) {
                second = i;
            }
        }
        return nums[first] >= 2 * nums[second] ? first : -1;
    }
};



int main()
{
    Solution S;
    vector<int> test{0,0,0,1};
    cout << S.dominantIndex(test) << endl;


    return 0;
}

