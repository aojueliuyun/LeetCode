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

// 2018.7.26 ------------> 100 problems


// achievement : 100 problems (all easy) sloved on leetcode --------> done 


// leetcode 448 : findDisappearedNumbers / 找到区间 [1, n] 中所有消失的数字
// require : O(1) space


// solution : use vector to save numbers
// time: O(n)
// space: O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> counts(nums.size()+1);
        for (auto x : nums) {
            counts[x] ++;
        }
        vector<int> ans;
        for (int i = 1; i < counts.size(); i ++) {
            if (counts[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};
 

// solution 2 : *= (-1)
// time: O(n)
// space: O(1)
class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int> & nums) {
        for (auto x : nums) {
            if (nums[abs(x)-1] > 0)
                nums[abs(x)-1] = nums[abs(x)-1] * (-1);
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > 0)
                ans.push_back(i+1);
        }
        return ans;
    }
};



template<typename T>
void printVec(vector<T> vec) {
    for (auto x : vec) cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> vec{4,3,2,7,8,2,3,1};
    Solution2 S;
    printVec(S.findDisappearedNumbers(vec));


    return 0;
}

