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

// 2018.8.3

// leetcode 661 : imageSmoother 


// solution 1 : just simulation
// execution time : 172 ms
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int r = M.size(), c = M[0].size();
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                int count = 0, sum = 0;
                for (int ni = max(i-1, 0); ni <= min(i+1, r-1); ni ++) {
                    for (int nj = max(j-1, 0); nj <= min(j+1, c-1); nj ++) {
                        count ++;
                        sum += M[ni][nj];
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};
 


int main()
{
    vector<vector<int>> M{{1,1,1}, {1,0,1}, {1,1,1}};
    Solution S;
    vector<vector<int>> res = S.imageSmoother(M);

    return 0;
}

