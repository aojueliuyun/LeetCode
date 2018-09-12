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
#include<unordered_map>
using namespace std;

// 2018.7.22

// leetcode 217 containsDuplicate


// solution 1 : use hash map / set
// time: O(n)
// space: O(n) 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> A;
        for (auto x : nums) {
            if (A.count(x) == 0) A.insert(x);
            else return true;
        }
        return false;
    }
};

// solution 2 : sort and traverse
// time: O(nlogn)
// space: O(1)
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        sort(nums.begin(), nums.end());
        for (int i=0; i < nums.size()-1; i ++) {
            if (nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};




int main()
{



    return 0;
}

