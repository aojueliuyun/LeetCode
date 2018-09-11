#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
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
#include<unordered_map>
using namespace std;

// 2018.7.21

// leetcode 172 : 求阶乘后的零个数

// solution
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for (long long i=5; i <= n; i*=5) res += n/i; // i could exceed INT_MAX, use long long
        return res;
    }
}; 



int main()
{
    Solution S;
    int n;
    while (cin >> n) {
        cout << S.trailingZeroes(n) << endl;
    }


    return 0;
}

