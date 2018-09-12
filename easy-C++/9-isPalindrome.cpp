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

// leetcode 9 : palindromic number


// Solution 1
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int rev = 0;
        int temp = x;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return false;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return false;
            rev = rev * 10 + pop;
        }
        return rev == temp;
    }
};


// Solution 2
// to string 
// C++11 --------> std::to_string(x)   (unsigned) (long long/long) int/double/float
class Solution2 {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string s = to_string(x);
        int len = s.length();
        for(int i = 0; i < len/2; i++){
            if(s[i] != s[len-1-i]) return false;
        }
        return true;
    }
};



static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


// Solution 3 : simplify of solution 1, do not need to jedge
class Solution3 {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int num = 0;
        int xx = x;
        while(x != 0){
            num = num*10 + x%10;
            x /= 10;
        } 
        if(num == xx) return true;
        return false;
    }
};




int main()
{
    Solution2 S;
    int x;
    while(cin >> x) {
        cout << S.isPalindrome(x) << endl;
    }

    return 0;
}

