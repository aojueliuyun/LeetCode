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

// 2018.7.24

// leetcode 387 : find first unique char / 找到字符串中第一个不重复的字符 

// solution :  use vector, only contain a to z
// time: O(n)
// space: O(1)
class Solution {
public:
    int firstUniqChar(string s) {
    	vector<pair<int, int>> vec(26);
    	for (int i = 0; i < s.length(); i ++) {
    		int num = s[i] - 'a';
    		vec[num].first ++;
    		if (vec[num].first == 1)
				vec[num].second = i;
		}
		int pos = s.length();
		for (auto x : vec) {
			if (pos > x.second && x.first == 1) pos = x.second;
		}
		if (pos == s.length()) return -1;
		return pos;
    }
};

int main()
{

	Solution S;
	string s;
	while (cin >> s) {
		cout << S.firstUniqChar(s) << endl;
	} 


	return 0;
}

