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

// leetcode 867 : transpose / 转置矩阵


// solution : 
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
    	int r = A.size(), c = A[0].size();
        vector<vector<int>> res(c, vector<int>(r, 0));
        for (int i = 0; i < r; i ++) {
        	for (int j = 0; j < c; j ++) {
        		res[j][i] = A[i][j];
			}
		}
		return res;
    }
};


int main()
{



	return 0;
}

