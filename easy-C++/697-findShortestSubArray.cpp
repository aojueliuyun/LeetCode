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

// 2018.8.13

// leetcode 697 : findShortestSubArray / 数组的度


// solution 1 : record the length of every subarray that includes every most number
// execution time : 112 ms
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> dict;
        vector<int> mostnum;
        for (auto x : nums) dict[x] ++;
        int most, maxnum = 0;
		for (auto x : dict) {
			if (x.second > maxnum) {
				maxnum = x.second;
				mostnum = {x.first};
			}
			else if (x.second == maxnum) {
				mostnum.push_back(x.first);
			}
		}
		int res = nums.size();
		for (auto x : mostnum) {
			int i = 0, j = nums.size()-1;
			while (i < nums.size()) {
				if (nums[i] == x) break;
				i ++;
			}
			while (j >= 0) {
				if (nums[j] == x) break;
				j --;
			}
			res = min(j-i+1, res);
		}
		return res;
    }
};



// solution 2 : record the position of every subarray
// ececution time : 52 ms
class Solution2 {
public:
    int findShortestSubArray(vector<int>& nums) {
    	int res = nums.size(), degree = 0;
    	unordered_map<int, int> m;     // record the number repeat numbers
        unordered_map<int, pair<int, int>> pos; // record the begin and end position of every subarray
        for (int i = 0; i < nums.size(); i ++) {
        	if (++m[nums[i]] == 1) {
        		pos[nums[i]] = {i, i};
			}
			else pos[nums[i]].second = i;
			degree = max(degree, m[nums[i]]);
		}
		for (auto x : m) {
			if (x.second == degree) {
				res = min(pos[x.first].second - pos[x.first].first + 1, res);	
			}
		}
		return res;
    }
};




int main()
{
	vector<int> vec{49999, 0, 0};
	Solution2 S;
	cout << S.findShortestSubArray(vec) << endl;


	return 0;
}

