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

// leetocde : 190  reverseBits : 颠倒 一个32位无符号整数的二进制位


// solution 1 : get it's binary order reverse it ans change into uint32_t
// time: O(logn)
// space: O(n)
// execution time: 12ms
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> order;
        while (n > 0) {
            order.push_back(n % 2);
            n /= 2;
        }
        order.insert(order.end(), 32-order.size(), 0);
        uint32_t res = 0;
        for (int x : order) {
            res = res*2 + x;
        }
        return res;
    }
};

// solution 2 : same as solution 1, just not use a vector
// time: O(n)
// space: O(1)
// execution time: 8ms
class Solution2 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i=0; i < 32; i++) {
//            res = (res<<1) +  ((n>>i) & 1);  // use bit operation 
            res = res*2 + n%2;
            n /= 2;
        }
        return res;
    }
};



int main()
{

    Solution2 S;
    uint32_t n;
    while (cin >> n) {
        cout << S.reverseBits(n) << endl; 
    }

    return 0;
}

