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

// 2018.8.31

// leetcode 18 : fourSum

// ok, now std::unique is useful, rememver you need sort the array first


// solution : double pointers just like problem 15 and 16
// time : O(n^3) 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};  // essential
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size()-3; i ++) {
            for (int j = i+1; j < nums.size()-2; j ++) {
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l ++;
                        r --;
                    }
                    else if (sum > target) {
                        r --;
                    }
                    else l ++;
                }
            }
        }
        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin());
        return res;
    }
};


int main()
{
    vector<int> test{-3,-2,-1,0,0,1,2,3};
    Solution S;
    vector<vector<int>> res = S.fourSum(test, 0);
    for (auto vec : res) {
        for (auto x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;


	return 0;
}

