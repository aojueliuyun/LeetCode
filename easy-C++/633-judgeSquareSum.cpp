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

// 2108.7.30

// leetcode 633 : judgeSquareSum / 判断一个数是否是两个数平方之和 


// solution : brute-force
// time : O(n)  || O(n^1/2 * n^1/2)
// space: O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; a <= floor(sqrt(c)); a ++) {
            int b = floor(sqrt(c-a*a));
            if (a*a + b*b == c) return true;
        }
        return false;
    }
};



int main()
{
    
    
    
    return 0;
}

