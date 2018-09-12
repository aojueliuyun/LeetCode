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

// 2018.7.24

// leetcode 344 reverseString

// solution : use std::reverse in <algorithm>
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};


// solution 2 : swap head and tail untill mid
class Solution2 {
public:
    string reverseString(string s) {
        if (s.length() <= 1) return s;
        for (int i = 0, j = s.length()-1; i < j; i ++, j --)
            swap(s[i], s[j]);
        return s;
    }
};

// solution 3 : return a new string
class Solution3 {
public:
    string reverseString(string s) {
        if (s.length() <= 1) return s;
        string res;
        for (int i = s.length()-1; i >= 0; i --) 
            res += s[i];
        return res;
    }
};


int main()
{



    return 0;
}

