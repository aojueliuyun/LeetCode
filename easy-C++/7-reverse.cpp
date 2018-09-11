#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<array>
using namespace std;

// 2018.7.14

// leetcode 9. reverse number 
// 反转一个32位整数    -123 --> -321 如果反转后整数溢出，则返回0 


// solution 1
// time: O(log(x)) 
class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        long long res = 0;
         // 负数比正数多一个, 最后一个case, 这里可以使用 INT_MAX & INT_MIN 
        if (x == - 0x7fffffff - 1) { 
            return 0;
        }
        if (x < 0) {
            neg = true;
            x = -x;
        }
        while(x != 0) { // 这里不需要显示计算出x的位数 
            res = 10*res + x%10;
            x /= 10;
        }
        if (res > 0x7fffffff) { // judge overflow 
            return 0;
        }
        return neg ? -res : res;
    }
};

// official solution : 
// 思路：类似于字符串反转
// time: O(log(x))
// 思路很棒，因为不需要用到 long long, 在加上最后一位之前即做了判断，而且非常严谨 
class Solution2 {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};



int main()
{
    Solution S;
    int x;
    cin >> x;
    cout << S.reverse(x) << endl;
    return 0;
}

