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

// 2018.7.23

// leetcode 283 : moveZeroes / 将数组中所有0移动到数组末尾,同时保持非0元素顺序 

// require: in-place
// time: O(n)
// space: O(1)  


// solution : use a new vector to save non-zero values
// time : O(n)
// space: O(n)  --------> not in-place
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	vector<int> temp;
    	for (auto x : nums) {
    		if (x != 0) temp.push_back(x);
		}
		for (int i = 0; i < temp.size(); i ++) {
			nums[i] = temp[i];
		}
		for (int i = temp.size(); i < nums.size(); i ++) {
			nums[i] = 0;
		}
    }
};


// solution 2 : in place 
// time: O(n)
// space: O(1)
class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
    	int n = 0;  // the number of zeros
    	for (int i = 0; i < nums.size(); i ++) {
    		if (nums[i] == 0) {
    			n ++;
    			continue;
			}
			else nums[i-n] = nums[i];
		}
		for (int i = nums.size()-n; i < nums.size(); i ++) nums[i] = 0;
    }
};

// solution 3 : same as solution 2 , just use two pointers --------- > simpler than solution 2.
// time: O(n)
// space; O(1)
class Solution3 {
public:
    void moveZeroes(vector<int>& nums) {
    	int j = 0;
    	for (int i = 0; i < nums.size(); i ++) {
    		if (nums[i] != 0) {
    			nums[j] = nums[i];
    			j ++;
			}
		}
		for (; j < nums.size(); j ++) nums[j] = 0;
    }
};



int main()
{



	return 0;
}

