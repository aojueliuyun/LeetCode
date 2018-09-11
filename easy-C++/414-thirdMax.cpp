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
#include<funciontal> // for greater<int>
#include<unordered_map>
using namespace std;

// 2018.7.26

// leetcode 414 : thirdMax / 第三大的数

// require : time complexity is O(n)


// solution 1: use long long
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first, second, third;
        first = second = third = LONG_LONG_MIN;   // have to use long long , not a good idea !
        for (auto x : nums) {
            if (x > first) {
                third = second;
                second = first;
                first = x;
            }
            else if (x < first && x > second) {
                third = second;
                second = x;
            }
            else if (x < second && x > third) {
                third = x;
            }
        }
        if (third == LONG_LONG_MIN) return first;
        return third;
    }
};


// solution 2 : use std::sort and std::unique in <algorithm>
class Solution2 {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if(nums.size() < 3)  return nums[0];
        else return nums[2];
    }
};




int main()
{
    int n;
    Solution S;
    while (cin >> n) {
        vector<int> vec(n);
        cout << "please input " << n << " values for vector : ";
        for (auto & x : vec) cin >> x;
        cout << S.thirdMax(vec) << endl;
    }


    return 0;
}

