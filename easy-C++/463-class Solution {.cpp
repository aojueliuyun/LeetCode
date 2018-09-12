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

// 2018.7.28

// leetcode 463 : islandPerimeter


// solution : just get how many grids is adjacent to every grid. || traverse
// time : O(n^2)
// space : O(n)
// execution time : 160 ms
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int row = grid.size(), column = grid[0].size();
        int ans = 0;
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < column; j ++) {
                if (grid[i][j] == 1) {
                    int adj = 0;
                    if (i-1 >= 0)     adj += grid[i-1][j];
                    if (i+1 < row)    adj += grid[i+1][j];
                    if (j-1 >= 0)     adj += grid[i][j-1];
                    if (j+1 < column) adj += grid[i][j+1];
                    ans += 4-adj;
                }
            }
        }
        return ans;
    }
};


int main()
{



    return 0;
}

