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

// leetcode 15 : threeSum

// key point I think : how to remove duplicates ? We should skip them, and std::unique is not a good choice.


// solution -1 : brute-force
// time : O(n^3)
// result : TLE -------> last three datas did not pass
class Solution_1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i+1; j < nums.size(); j ++) {
                for (int k = j+1; k < nums.size(); k ++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        res.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin()); // std::unique in <algorithm>
        return res;
    }
};


// solution -2: use hash map based on solution -1
// time : O(n^2)
// result : also TLE ----------> same as solution -1
class Solution_2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dict;
        for (auto x : nums) dict[x] ++;
        for (int i = 0; i < nums.size(); i ++) {
            dict[nums[i]] --;  // ensure not use one value twice
            for (int j = i+1; j < nums.size(); j ++) {
                dict[nums[j]] --;
                int need = - nums[i] - nums[j];
                if (dict[need] > 0) {
                    vector<int> tmp{nums[i], nums[j], need};
                    sort(tmp.begin(), tmp.end());
                    res.push_back(tmp);
                }
                dict[nums[j]] ++;
            }
            dict[nums[i]] ++;
        }
        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin());
        return res;
    }
};



// solution : one outter loop to traverse, one inner loop use double pointers to find result
// time : O(n^2) --------> better than solution 2
// execution time : 88 ms
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size()-2; i ++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {  // skip duplicates
                int l = i+1, r = nums.size()-1, sum = 0-nums[i];
                while (l < r) {
                    if (nums[l] + nums[r] == sum) {
                        res.push_back({nums[i], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l+1]) l ++;  // skip duplicates
                        while (l < r && nums[r] == nums[r-1]) r --;
                        l ++;
                        r --;
                    }
                    else if (nums[l] + nums[r] < sum) {
                        l ++;
                    }
                    else {
                        r --;
                    }
                }
            }
        }
        return res;
    }
};




int main()
{
    Solution S;
    vector<int> nums{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    auto res = S.threeSum(nums);
    for (auto vec : res) {
        for (auto x : vec) {
            cout << x << ", ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

