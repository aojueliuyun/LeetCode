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

// leetcode 766 : isToeplitzMatrix / ÍÐÆÕÀû´Ä¾ØÕó


// solution 1 : get the liner equation for every diagonal line which is not neccessary.
// time: O(m*n)
// execution time : 20 ms
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        for (int i = -c+1; i < r; i++) {
        	int val = -1;
        	for (int x = 0; x < c; x ++) {
        		int y = x + i;
        		if (y >= 0 && y < r) {
        			if (val == -1) 
						val = matrix[y][x];
        			else if (val != matrix[y][x]) 
						return false;
				}
			}
		}
		return true;
    }
}; 


// solution 2 : simpler
// time : O(m*n)
// execution time : 16 ms
class Solution2 {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r; i ++) {
        	for (int j = 0; j < c; j ++) {
        		if (i+1 < r && j+1 < c && matrix[i+1][j+1] != matrix[i][j]) {
        			return false;
				}
			}
		}
		return true;
    }
};



int main()
{



	return 0;
}

