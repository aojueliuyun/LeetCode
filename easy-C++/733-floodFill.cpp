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

// leetcode 733 : floodFill


// solution : BFS / use queue --------> DFS also works.
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int val = image[sr][sc];
        if (val == newColor) {
            return image;
        }
        int r = image.size(), c = image[0].size(); 
        queue<pair<int, int>> Q;
        Q.push({sr, sc});
        image[sr][sc] = newColor;
        int d[4][2] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i ++) {
                int x = cur.first + d[i][0];
                int y = cur.second + d[i][1];
                if (x >=0 && x < r && y >= 0 && y < c && image[x][y] == val) {
                    image[x][y] = newColor;
                    Q.push({x, y});
                }
            }
        }
        return image;
    }
};




int main()
{
    Solution S;
    vector<vector<int>> vec{{0, 0, 0}, {0, 1, 1}};
    auto res = S.floodFill(vec, 1, 1, 1);
    for (int i = 0; i < res.size(); i ++) {
        for (int j = 0; j < res[0].size(); j ++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}

