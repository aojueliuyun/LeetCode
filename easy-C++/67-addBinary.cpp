#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<unordered_map>
using namespace std;

// 2018.7.15

// leetcode 67 : add Binary 


// Solution 1 : reverse and fill two strings (make two strings same length), get sum then reverse back
// time: O(n)
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());                 // reverse two string to calculate 
        reverse(b.begin(), b.end());
        if (a.length() < b.length()) {               // fill two strings to make them have same length
            a.append(b.length() - a.length(), '0');
        }
        else b.append(a.length() - b.length(), '0');
        string ans;
        int radix = 2, carry = 0, sum = 0;
        for (int i = 0; i < a.length(); i++) {
            sum = (a[i] - '0') + (b[i] - '0');
            ans.push_back((sum + carry)% radix + '0');
            carry = (sum + carry) / radix;
        }
        if(carry > 0) ans.push_back('0' + carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// Solution 2 : no reverse ------------- to be coontinued


int main()
{
    string a,b;
    Solution S;
    while(cin >> a >> b) {
        cout << S.addBinary(a, b) << endl;
    }

    return 0;
}

