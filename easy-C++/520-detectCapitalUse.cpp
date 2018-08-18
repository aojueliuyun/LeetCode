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

// 2018.7.29

// leetcode 520 : detectCapitalUse / ¼ì²â´óÐ´×ÖÄ¸


// solution 1 : 
class Solution {
public:
    bool detectCapitalUse(string word) {
    	if (word.length() <= 1) return true;
        if (word[0] >= 'A' && word[0] <= 'Z')  {
        	int count1 = 1, count2 = 1;
        	for (int i = 1; i < word.length(); i ++) {
        		if (word[i] >= 'a' && word[i] <= 'z') {
        			count1 ++;
				}
				else count2 ++;
			}
			return count1 == word.length() || count2 == word.length();
		}
		else {
			for (auto c : word) {
				if (c >= 'A' && c <= 'Z') return false;
			}
			return true;
		}
    }
}; 


// solution 2 : use several bool variable
class Solution2 {
public:
    bool detectCapitalUse(string word) {
    	bool isHeadLower = islower(word[0]);
    	bool isAllUpper = true, isAllLower = true;
    	for (int i = 1; i < word.length(); i ++) {
    		if (islower(word[i])) {
    			isAllUpper = false;
			}
			else {
				isAllLower = false;
			}
			if (isHeadLower && isAllUpper) return false;
			if (!isAllUpper && !isAllLower) return false;
		}
		return true;
    }
};



int main()
{
	string s;
	Solution2 S;
	while (cin >> s) {
		cout << S.detectCapitalUse(s) << endl;
	}


	return 0;
}

