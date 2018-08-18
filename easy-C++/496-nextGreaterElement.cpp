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
using namespace std;

// 2018.7.28

// leetcode 496 : nextGreaterElement 


// solution : jsut simulation
// time: O(mn)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    	vector<int> res(findNums.size());
        for (int i = 0; i < findNums.size(); i ++) {
        	int j;
        	for (j = 0; j < nums.size(); j ++) {
        		if (nums[j] == findNums[i]) break;
			}
			bool find = false;
			for (; j < nums.size(); j ++) {
				if (nums[j] > findNums[i]) {
					res[i] = nums[j];
					find = true;
					break;
				};
			}
			if (!find) res[i] = -1;
		}
		return res;
    }
};



int main()
{


	return 0;
}

