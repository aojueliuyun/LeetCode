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
#include<bitset>
#include<unordered_map>
using namespace std;


// 2018.7.26

// leetcode : 434 countSegments / 统计单词中的单词数


// solution : 
class Solution {
public:
    int countSegments(string s) {
    	int last = -1; // the position of last space
    	int count = 0;
    	for (int i = 0; i < s.length(); i ++) {
    		if (s[i] == ' ') {
    			if (i == last + 1) last ++;
    			else {
    				last = i;
    				count ++;
				}
			}
		}
		if (last != s.length()-1)
			count ++;
		return count; 
    }
};




 



int main()
{


	return 0;
}

