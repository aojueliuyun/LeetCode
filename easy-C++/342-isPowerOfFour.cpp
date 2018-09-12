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

// 2018.7.24

// leetcode 342: isPowerOfFour 

// solution 1 : use shift and &
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        while (!(num & 3)) num >>= 2;
        return num == 1;
    }
}; 

// solution 2 : do not use loop or recursion
class Solution2 {
public:
    bool isPowerOfFour(int num) {
        return (num & (num-1)) == 0 && (num-1) % 3 == 0;
    }
}; 


int main()
{
    int n;
    Solution2 S;
    while (cin >> n) {
        cout << S.isPowerOfFour(n) << endl;
    }


    return 0;
}

