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

// leetcode 28 : strStr function


// Solution 1  : directly compare
// use time: 500ms -------------> no compare, no harm. better use STL function
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int len1 = haystack.length(), len2 = needle.length();
        for(int now = 0; now < len1; now ++) {
            int i = now, temp_sub = 0;
            while (i < len1 && temp_sub < len2 && haystack[i] == needle[temp_sub]) { 
                i ++;
                temp_sub ++;
            }
//            cout << now << ',' << i << ',' << temp_sub << endl;
            if (temp_sub == len2) return now;
        }
        return -1;
    }
};


// Solution 2 
// use string::substr(pos, len)     // if pos + len > length() then fetch longest substring 
// use time: 4ms
class Solution2 {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int len1 = haystack.length(), len2 = needle.length();
        if (haystack.empty() || len1 < len2) return -1;
        for (int i = 0; i <= len1-len2; i ++) {
            if (haystack.substr(i, len2) == needle) return i;
        } 
        return -1;
    }
};
 

int main()
{
    Solution2 S;
    string a,b;
    while (cin >> a >> b) {
        cout << S.strStr(a, b);
    }


    return 0;
}

