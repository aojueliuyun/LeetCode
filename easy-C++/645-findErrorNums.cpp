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

// 2018.8.3

// leetcode 645 : findErrorNums / ´íÎóµÄ¼¯ºÏ


// solution 1 : use hash map
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    	vector<int> record(nums.size(), 0);
    	vector<int> res(2, 0);
    	for (auto x : nums) {
    		record[x-1] ++;
		}
		for (int i = 0; i < record.size(); i ++) {
			if (record[i] == 2) res[0] = i+1;
			if (record[i] == 0) res[1] = i+1;
		}
    	return res;
    }
};



int main()
{



	return 0;
}

