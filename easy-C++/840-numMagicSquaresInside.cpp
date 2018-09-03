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

// 2018.8.20

// leetcode 840 : numMagicSquaresInside


// solution : attention every element need >= 1 && <= 9
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        if (r < 3 || c < 3) return 0;
        int count = 0;
        for (int i = 0; i < r-2; i ++) {
            for (int j = 0; j < c-2; j ++) {
                int tmp = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
                bool flag = true;
                int sum3 = 0;
                for (int k = 0; k < 3; k ++) {
                    int sum1 = 0, sum2 = 0;
                    for (int s = 0; s < 3; s ++) {
                        if (grid[i+k][j+s] >=1 && grid[i+k][j+s] <= 9) {
                            sum1 += grid[i+k][j+s];
                            sum2 += grid[i+s][j+k];
                        }
                        else {
                            flag = false;
                            break;
                        }
                        
                    }
                    if (sum1 != tmp || sum2 != tmp) {
                        flag = false;
                        break;
                    }
                    sum3 += grid[i+k][j+k];
                }
                if (sum3 == tmp && flag) count ++;
            }
        }
        return count;
    }
};



int main()
{



	return 0;
}

