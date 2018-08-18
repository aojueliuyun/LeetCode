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

// 2018.7.30

// leetcode 868 : binaryGap / 二进制间距


// solution 
class Solution {
public:
    int binaryGap(int N) {
        int pos = -1, last1 = -1, gap = 0, maxgap = 0;
    	while (N) {
    		pos ++;
    		if (N & 1) {
    			if (last1 == -1) last1 = pos; // first 1
    			else {
    				gap = pos - last1;
    				maxgap = max(gap, maxgap);
    				last1 = pos;
				}
			}
			N >>= 1;
		}
		return maxgap;
    }
}; 


int main()
{



	return 0;
}

