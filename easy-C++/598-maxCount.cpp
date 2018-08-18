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

// leetcode 598 : maxCount / ·¶Î§ÇóºÍ II 


// solution -1 : jsut simulation
// time: O(mnk) k is th ops.size()
// space: O(mn)
// result ---------> memory limit exceed -------> simulation is not working !!!  Giving up thinking is bad !!!
class Solution_1 {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
    	vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (auto op : ops) {
        	for (int i = 0; i < m; i ++) {
        		for (int j = 0; j < n; j ++) {
        			if (i < op[0] && j < op[1])
        				matrix[i][j] ++;
				}
			}
		}
		int maxval = 0, count = 0;
		for (auto row : matrix) {
			for (auto x : row) {
				if (x == maxval) {
					count ++;
				}
				else if (x > maxval) {
					count = 1;
					maxval = x;
				} 
			}
		}
		return count;
    }
}; 


// solution 1 : find the minimum number of ops for row and coolumn ||--------> Don't give up thinking !!!
// time: O(k)  k = ops.size()
// space: O(1)
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
    	if (ops.empty()) return m*n;
    	int minr = ops[0][0], minc = ops[0][1]; // row ans column
    	for (auto x : ops) {
    		minr = min(minr, x[0]);
    		minc = min(minc, x[1]);
		}
		return minr * minc;
    }
};



int main()
{



	return 0;
}

