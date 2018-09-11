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

// leetcode 54 : spiralOrder(vector


// solution : 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int dir = 0, x = 0, y = 0;
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<bool>> flag(r, vector<bool>(c, false));
        vector<int> res;
        while (x >= 0 && x < r && y >= 0 && y < c && !flag[x][y]) {
            res.push_back(matrix[x][y]);
            flag[x][y] = true;
            int tmpx = x + d[dir][0];
            int tmpy = y + d[dir][1];
            if (tmpx >= r || tmpx < 0 || tmpy >= c || tmpy < 0 || flag[tmpx][tmpy]) {
                dir = (dir+1) % 4;
            }
            x += d[dir][0];
            y += d[dir][1];
        }
        return res;
    }
};


int main()
{
    vector<vector<int>> test{{1,2,3}, {4,5,6}, {7,8,9}};
    Solution S;
    vector<int> res = S.spiralOrder(test);
    for (auto x : res) {
        cout << x << " ";
    }
    cout << endl;


    return 0;
}

