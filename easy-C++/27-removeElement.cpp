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

// leetcode 27 : remove Element

// solution 1 : use iterator
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        auto temp = nums.begin();
        for (auto iter = nums.begin(); iter != nums.end(); iter ++) {
        	if (* iter != val) {
        		* temp = * iter;
        		temp ++;
			}
		}
		return temp - nums.begin();
    }
};


// solution 2 : just compare
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j ++) {
            if (nums[j] != val) {
                nums[i ++] = nums[j];
            }
        }
        return i;
    }
};


int main()
{



	return 0;
}

