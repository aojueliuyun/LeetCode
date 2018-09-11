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

// leetcode 217 containsNearbyDuplicate / 判断数组是否包含临近不超过距离k的重复元素 


// thinking : use queue, but queue doesn't support traversal !!!--------> so Failed

// the difference between map and unordered_map :
// implementation : map ----> red & black tree , unordered_map ------> hash map
// using : map --------> ordered for sorting, unordered_map -----> for searching, unordered


// solution 1 : just use vector and for loop to judge
// time: O(n*k)
// space: O(1)
// execution time: 1480ms
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i=0; i < nums.size(); i ++) {
            for (int j=1; j <= k; j ++) {
                if (i+j < nums.size() && nums[i+j] == nums[i]) return true;
            }
        }
        return false; 
    }
};


// solution 2 : use hash map
// time : O(n)
// space: O(k)
// execution time : 20ms
class Solution2 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        for (int i=0; i < nums.size(); i ++) {
            if (dict.find(nums[i]) != dict.end() && dict[nums[i]] >= i-k) return true;
            else dict[nums[i]] = i;
        }
        return false;
    }
};




int main()
{
    vector<int> v{1,2,3,1};
    Solution S;
    int k;
    while (cin >> k) {
        cout << S.containsNearbyDuplicate(v, k) << endl; 
    }    


    return 0;
}

