#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<unordered_map>
using namespace std;

// 2018.7.15

// 35 Search Insert Position

// Solution 1: brute-force
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i ++) {
        	if (target <= nums[i]) return i;
		}
		return nums.size();
    }
};
 
// Solution 2: binary search -------------> 处理各种边界情况，一点都不优美 ------> 不如使用 STL  
class Solution2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
		while(left < right) {
			mid = (left + right) / 2;
			if(nums[mid] == target) return mid;
			else if(nums[mid] > target) right = mid;
			else left = mid;
			if (nums[right] < target) return right + 1;
			if (nums[left] >= target) return left;
			if (right - left == 1) return right;
		}
		return nums[0] < target ? 1 : 0; 
    }
};


// Solution 3: STL -----> binary search : std::lower_bound() in <algorithm>
class Solution3 {
public:
    int searchInsert(vector<int>& nums, int target) {
//        if (nums.empty()) return 0;
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
 


int main()
{


	return 0;
}

