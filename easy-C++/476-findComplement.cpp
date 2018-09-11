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

// leetcode 476 : findComplement / 将一个数按二进制位取反，保持同样长度


// solution 1 : get it's bits and shift
class Solution {
public:
    int findComplement(int num) {
        int bits = 0;
        int temp = num;
        while (num) {
            num >>= 1;
            bits ++;
        }
        return (~temp << (32-bits)) >> (32-bits);
    }
};

// solution 2 : get it's mask and xor
class Solution2 {
public:
    int findComplement(int num) {
        int temp = num, mask = 0;
        while (temp) {
            temp >>= 1;
            mask = (mask << 1) + 1;
        }
        return num ^ mask;
    }
};



int main()
{
    int n;
    Solution2 S;
    while (cin >> n) {
        cout << S.findComplement(n) << endl;
    }

    return 0;
}

