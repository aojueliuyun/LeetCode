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

// 2018.7.22

// leetcoee 231 isPowerOfTwo 


// solution 1 : divide
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n) {
            if (n == 1) break;
            if (n % 2 == 1) return false;
            n /= 2;
        }
        return true;
    }
};


// solution 2 : multiply -------------> easy and clean
class Solution2 {
public:
    bool isPowerOfTwo(int n) {
        int i=1;
        for (int j = 0; j < 31 && i < n; j ++) i <<= 1;
        return i == n;
    }
};


// solution 3: bit operation  ----------------> tricky
class Solution3 {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n-1));
    }
};


int main()
{
    int n;
    Solution3 S;
    while (cin >> n) {
        cout << S.isPowerOfTwo(n) << endl;
    }


    return 0;
}

