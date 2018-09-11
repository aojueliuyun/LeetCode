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
// ��תһ��32λ����    -123 --> -321 �����ת������������򷵻�0 


// solution 1
// time: O(log(x)) 
class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        long long res = 0;
         // ������������һ��, ���һ��case, �������ʹ�� INT_MAX & INT_MIN 
        if (x == - 0x7fffffff - 1) { 
            return 0;
        }
        if (x < 0) {
            neg = true;
            x = -x;
        }
        while(x != 0) { // ���ﲻ��Ҫ��ʾ�����x��λ�� 
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
// ˼·���������ַ�����ת
// time: O(log(x))
// ˼·�ܰ�����Ϊ����Ҫ�õ� long long, �ڼ������һλ֮ǰ�������жϣ����ҷǳ��Ͻ� 
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

