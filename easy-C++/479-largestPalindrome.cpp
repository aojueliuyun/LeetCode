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

// leetcode 479 : largestPalindrome 

// WTF !!!


// solution : 
class Solution {
public:
    int largestPalindrome(int n) {
        
    }
    bool isPalindrome(int n) {
        string s = to_string(n);
        for (int i = 0, j = s.length()-1; i < j; i ++, j --) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
}; 


int main()
{
    int n;
    Solution S;
    while(cin >> n) {
        cout << S.isPalindrome(n) << endl;
    }


    return 0;
}

