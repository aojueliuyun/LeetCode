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

// leetcode 383 canConstruct / 判断一个字符串是否能由另一个字符串中的字母构成


// solution : use unordered_map
// time: O(n)
// space: O(n)
// execution time: 40ms -----> 16ms (add the statement blow)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dict;
		for (auto c : magazine) dict[c] ++;
		for (auto c : ransomNote) {
			if (dict[c] == 0) return false;
			else dict[c] --;
		}
		return true; 
    }
};

static auto __ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// solution 2 : just use string::back(), string::find(), string::pop_back() || in place
// time: O(n)
// space: O(1)
// execution time: 64ms -----> 4ms (add the statement above)
class Solution2 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (auto c : ransomNote) {
        	int pos = magazine.find(c);
        	if (pos != string::npos) {
        		swap(magazine[pos], magazine.back());
        		magazine.pop_back();
			}
			else return false;
		}
		return true;
    }
};

int main()
{
	string a, b;
	Solution S;
	while (cin >> a >> b) {
		cout << S.canConstruct(a, b) << endl;
	}


	return 0;
}

