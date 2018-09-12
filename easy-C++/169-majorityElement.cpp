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

// 2018.7.18

// leetcode 169 : majorityElement

// solution : traverse and save to hash map
// time: O(n)
// space: O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> record;
        for (auto x : nums) {
            if (record.find(x) == record.end())
                record[x] = 1;
            else record[x] ++;
        }
        for (auto p : record) {
            if (p.second > nums.size() / 2)
                return p.first;
        }
        return 0;
    }
};


// solution 2 : sort and get nums[size/2]
// time: O(nlogn)
// space: O(1)
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-1];
    }
};

// solution 3 : the simplification if solution 1
// time: O(n)
// space: O(1)
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (auto x : nums)
            if (++dict[x] > nums.size()/2) return x; // when x in not in map, there will insert a map[key] = default value (for int it's 0)
        return -1;
    }
};




int main()
{
    vector<int> V{3,2,3};
    Solution3 S;
    cout << S.majorityElement(V) << endl;


    return 0;
}

