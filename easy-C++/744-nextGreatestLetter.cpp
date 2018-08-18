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

// 2018.8.17

// leetcode 744 : nextGreatestLetter / 寻找比目标字母大的最小字母


// solution : traverse a cyclic vector
// time: O(n)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        unordered_map<char, int> dict;
        for (auto c : letters) dict[c] ++;
        for (char c = target+1; c <= 'z'; c ++) {
        	if (dict[c] > 0) return c;
		}
		for (char c = 'a'; c < target; c ++) {
			if (dict[c] > 0) return c;
		}
    }
};


// solution 2 : just traverse, because the input array is ordered .
class Solution2 {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (auto c : letters) {
        	if (c > target) return c;
		}
		return letters[0];
    }
};


int main()
{



	return 0;
}

