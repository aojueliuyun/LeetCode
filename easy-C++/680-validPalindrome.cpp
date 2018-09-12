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
#include<unordered_set>
using namespace std;

// 2018.8.4

// leetcode 680 : validPalindrome 


// solution : 
// execution time : 108 ms
class Solution {
public:
    bool validPalindrome(string s) {
        return valid(s, 0, s.length()-1, 1);
    }
    bool valid(const string & s, int i, int j, int count) {
        if (i == j) return true;
        if (s[i] == s[j]) {
            if (j == i+1) return true;
            return valid(s, i+1, j-1, count)
        }
        else {
            if (count == 0) return false;
            return valid(s, i+1, j, count-1) || valid(s, i, j-1, count-1);
        }
    }
};




int main()
{



    return 0;
}

