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

// leetcode 443 : compress / Ñ¹Ëõ×Ö·û´®

// require : in place / O(1) space

// solution :  
class Solution {
public:
    int compress(vector<char>& chars) {
    	char cur = chars[0];
    	int count = 1, pos = 0;
    	for (int i = 1; i < chars.size(); i ++) {
    		if (chars[i] == cur) {
    			count ++;
			}
			else {
				chars[pos++] = cur;		
				if (count != 1) {
					for (auto ch : to_string(count))
						chars[pos++] = ch;
				}
				cur = chars[i];
				count = 1;
			}
		}
		chars[pos++] = cur;		
		if (count != 1) {
			for (auto ch : to_string(count))
				chars[pos++] = ch;
		}
		return pos;
    }
};

int main()
{



	return 0;
}

