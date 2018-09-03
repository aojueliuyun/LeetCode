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

// 2018.8.21

// leetcode 400 : findNthDigit


// solution : 
class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;
        long long num = 0, width = 0, sum = 0;
        while (n > num) {
            n -= num * width;
            num = (num+1)*10-1;
            width ++;
        }
        int res = num % 10 + (n+width-1)/width;
        n %= width;
        if (n == 0) return res % 10;
        for (int i = 0; i < width-n; i ++) {
            res /= 10;
        }
        return res % 10;
    }
};



int main()
{
    Solution S;
    cout << S.findNthDigit(10) << endl;


	return 0;
}

