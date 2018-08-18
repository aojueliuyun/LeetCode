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

// 20018.7.15

// leetcode 136 singleNumber 只出现一次的数字

// solution 1
// time: O(n)
// space: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> M;
        for (int x : nums) {
        	M[x] ++;
        	if (M[x] == 2) M.erase(x);
		}
		for (auto element : M) return element.first;
    }
}; 

// solution 2
// xor / ^ operation ---------> so tricky 很骚 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto x : nums) {
        	res ^= x;
		}
		return res;
    }
};

// to speed up , you need this 
static const auto __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int main()
{



	return 0;
}

