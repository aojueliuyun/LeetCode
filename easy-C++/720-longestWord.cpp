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

// 2018.8.14

// leetcode 720 : longestWord 


// solution : use set to save all words that has possibility to be the answer
// time : O( words.size() )
class Solution {
public:
    string longestWord(vector<string>& words) {
        vector<vector<string>> dict(31, vector<string>(0));
        for(auto s : words) {
        	dict[s.length()].push_back(s);
		}
		unordered_set<string> S(dict[1].begin(), dict[1].end());
		int maxlen = 1;
		string res = dict[1][0]; // at least has one word
		for (int i = 2; i < dict.size(); i ++) {
			for (auto word : dict[i]) {
				if (S.count(word.substr(0, word.length()-1))) {
//					if (maxlen < word.length()) {
//						res = word;
//						maxlen = word.length();
//					}
//					else {
//						res = min(res, word);
//					}
					res = res.length() < word.length() ? word : min(res, word);
					S.insert(word);
				}
			}
		}
		return res;
    }
};



int main()
{
	vector<string> vec{"t","ti","tig","tige","tiger","e","en","eng","engl","engli","englis","english","h","hi","his","hist","histo","histor","history"};
	Solution S;
	cout << S.longestWord(vec) << endl;


	return 0;
}

