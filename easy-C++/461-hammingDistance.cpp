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

// leetcode 461 hammingDistance


// solution 1 : use xor
class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        int ans = 0;
        while (tmp) {
            if (tmp & 1) ans ++;
            tmp >>= 1;
        }
        return ans;
    }
}; 


int main()
{
    int x, y;
    Solution S;
    while (cin >> x >> y) {
        cout << S.hammingDistance(x, y) << endl;
    }


    return 0;
}

