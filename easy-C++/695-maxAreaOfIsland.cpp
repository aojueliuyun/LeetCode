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

// 2018.8.13

// leetcode 695 : maxAreaOfIsland / 岛屿的最大面积


// solution : BFS, use queue
// execution time : 20 ms
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i ++) {
        	for (int j = 0; j < c; j ++) {
        		if (grid[i][j]) {
        			int area = 0;
        			queue<pair<int, int>> Q;  // use queue to BFS
        			Q.push({i, j});
        			grid[i][j] = 0;
        			while (!Q.empty()) {
        				auto x = Q.front();
        				Q.pop();
        				area ++;
        				int ii = x.first, jj = x.second;  // shit name, I know
        				if (jj+1 < c && grid[ii][jj+1]) { // can use a loop replace 4 if-statements
        					Q.push({ii, jj+1});
        					grid[ii][jj+1] = 0;
						}
        				if (ii+1 < r && grid[ii+1][jj]) {
        					Q.push({ii+1, jj});
        					grid[ii+1][jj] = 0;
						}
        				if (jj-1 >= 0 && grid[ii][jj-1]) {
        					Q.push({ii, jj-1});
        					grid[ii][jj-1] = 0;
						}
        				if (ii-1 >= 0 && grid[ii-1][jj]) {
        					Q.push({ii-1, jj});
        					grid[ii-1][jj] = 0;
						}
					}
					maxarea = max(maxarea, area);
				}
			}
		}
		return maxarea;
    }
};


// solution 2 : DFS , recursion
// execution time : 44 ms
class Solution2 {
public:
    int maxAreaOfIsland(vector<vector<int>> & grid) {
        int r = grid.size(), c = grid[0].size();
        int area = 0;
        for (int i = 0; i < r; i ++) {
        	for (int j = 0; j < c; j ++) {
        		if (grid[i][j])
        			area = max(dfs(grid, i, j), area);
			}
		}
		return area;
    }
    int dfs(vector<vector<int>> & grid, int x0, int y0) {
    	int r = grid.size(), c = grid[0].size();
    	int sum = 1;
    	int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    	grid[x0][y0] = 0;
    	for (int i = 0; i < 4; i ++) {
    		int x = x0 + d[i][0];
    		int y = y0 + d[i][1];
    		if (x >= 0 && y >=0 && x < r && y < c && grid[x][y]) {
    			sum += dfs(grid, x, y);
			} 
		}
		return sum;
	}
};




int main()
{
	vector<vector<int>> V(10, vector<int>(2, 1));
	Solution2 S;
	cout << S.maxAreaOfIsland(V) << endl;


	return 0;
}

