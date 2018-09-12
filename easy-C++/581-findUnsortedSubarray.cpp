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

// 2018.7.30

// leetcode 581 : findUnsortedSubarray


// solution : brute-force attack || two pointers, find left and right
// time: wrost O(n^2)  best O(n)  average O(n^2) --> not sure
// space: O(1)
// execution time: 204 ms ------> not so good
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        bool lt = true, gt = true;
        while (left < right) {
             for (int i = left+1; lt && i <= right; i ++) {
                 if (nums[left] <= nums[i]) {
                     lt = true;
                }
                else lt = false;
            }
            if (lt) left ++;
            for (int j = right-1; gt && j >= left; j --) {
                if (nums[right] >= nums[j]) {
                    gt = true;
                }
                else gt = false;
            }
            if (gt) right --;
            if (!lt && !gt) return right-left+1; 
        }
        return 0;
    }
};


// solution 2 : use an extra array assigned by nums, sort it and compare with nums to find left and right.
// time: O(nlogn) wrost for sorting. 
// space: O(n)
// execution time : 48 ms -----> not very good
class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n-1;
        vector<int> v = nums;
        sort(v.begin(), v.end());
        while (i < n && nums[i] == v[i]) i++;
        while (j > i && nums[j] == v[j]) j--;
        return j == i ? 0 : j-i+1;
    }
};


// solution 3 : record the maximum value from left to right, minimum value from right to left, only need one round traversal.
// time: O(n)
// space: O(1)
// execution time: 44 ms ------> nearly best 
class Solution3 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0; // initial values for the corner case that the array is already in ascending order
        int maxval = nums[0];
        int minval = nums[n-1];
        for(int i = 0; i < n; i ++) {
            maxval = max(nums[i], maxval);
            minval = min(nums[n-i-1], minval);
            if (nums[i] < maxval) right = i;
            if (nums[n-1-i] > minval) left = n-1-i;
        }
        return left == right ? 0 : right-left+1;
    }
};



int main()
{
    vector<int> test{1,2,3,4};
    Solution S;
    cout << S.findUnsortedSubarray(test) << endl;


    return 0;
}

