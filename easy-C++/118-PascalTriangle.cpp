#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<unordered_map>
using namespace std;

// 2018.7.16

// leetcode 118 : Pascal's Triangle / Ñî»ÔÈý½Ç 

// solution : use padcal identity 

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> C(numRows);
		for (int n = 0; n < numRows; n++) {
			C[n].resize(n+1);               // attention : reserve() & resize()
			C[n][0] = C[n][n] = 1; 
		}
		for (int n = 2; n < numRows; n++)
			for (int i = 1; i < n; i++) 
				C[n][i] = C[n-1][i] + C[n-1][i-1];
		return C;
    }
};


// other : do not resize , use push_back()
class Solution2 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i ++)
        {
            vector<int> temp({1});
            int j = 1;
            for (; j < i; j ++)
            {
                temp.push_back(ans[i - 1][j-1]+ans[i - 1][j]);
            }
            if (j == i)
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
	// vector test 
	// reverse() & resize()
	vector<int> v(4);
	cout << v.size() << endl;
	v.push_back(10);
	cout << v.size() << endl;
	v.resize(10);
	cout << v.size() << endl;


	return 0;
}

