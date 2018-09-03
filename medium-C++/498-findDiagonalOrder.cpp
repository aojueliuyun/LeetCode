#include<iostream>
#include<fstream>
#include<sstream>
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

// 2018.8.26

// leetocde 498 : findDiagonalOrder


// solution 1 : 
// execution time : 256 ms
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r+c-1; i ++) {
            int x = 0, y = 0;
            if (i % 2 == 0) {
                for (x = i; x >= 0; x --) {
                    y = i - x;
                    if (x >= 0 && x < r && y >= 0 && y < c) {
                        res.push_back(matrix[x][y]);
                    }
                }
            }
            else {
                for (y = i; y >= 0; y --) {
                    x = i - y;
                    if (x >= 0 && x < r && y >= 0 && y < c) {
                        res.push_back(matrix[x][y]);
                    }
                }
            }
        }
        return res;
    }
};


// solution 2 : 
// execution time : 68 ms
class Solution2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int r = matrix.size(), c = matrix[0].size(), i = 0, j = 0;
        vector<int> res(r*c, 0);
        int dir[2][2] = {{-1, 1}, {1, -1}};
        int order = 0;
        for (int k = 0; k < r*c; k ++) {
            res[k] = matrix[i][j];
            i += dir[order][0];
            j += dir[order][1];
            if (i >= r) { i = r-1; j += 2; order = 1-order; }
            if (j >= c) { j = c-1; i += 2; order = 1-order; }
            if (i < 0) { i = 0; order = 1-order; }
            if (j < 0) { j = 0; order = 1-order; }
        }
        return res;
    }
};


int main()
{
    vector<vector<int>> test{{1,2,3}, {4,5,6}, {7,8,9}};
    Solution2 S;
    vector<int> res = S.findDiagonalOrder(test);
    for (auto x : res) {
        cout << x << " ";
    }
    cout << endl;


	return 0;
}

