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

// leetcode 504 : convertToBase7 


// solution
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool neg = num < 0;
        num = abs(num);
        string res;
        while (num) {
            res = to_string(num % 7) + res;
            num /= 7;
        }
        if (neg) res = '-' + res;
        return res;
    }
}; 


int main()
{
    int n;
    Solution S;
    while (cin >> n) {
        cout << S.convertToBase7(n) << endl;
    } 


    return 0;
}

