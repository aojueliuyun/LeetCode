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
#include<bitset>
#include<unordered_map>
using namespace std;

// 2018.7.26

// leetcode 415 : addStrings


// solution : just simulation
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
           reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if (num1.length() > num2.length()) // fill 0 to make two string same length
            num2.append(num1.length() - num2.length(), '0');
        else num1.append(num2.length() - num1.length(), '0');
        int carry = 0;
        for (int i = 0; i < num1.length(); i ++) {
            int temp = num1[i] - '0' + num2[i] - '0' + carry; // must add carry
            res += '0' + temp % 10;
            carry = temp / 10;
        }
        if (carry != 0)
            res += carry + '0';
        reverse(res.begin(), res.end());
        return res;
    }
};



int main()
{
    string a, b;
    Solution S;
    while (cin >> a >> b) {
        cout << S.addStrings(a, b) << endl;
    }
    

    return 0;
}

