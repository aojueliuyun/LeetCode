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

// 2018.7.26

// leetcode 409 : longestPalindrome / 输入一个字符串，找出其能构成的最长回文字符串


// solution : use hash map to count
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> dict;
        for (auto c : s) {
            dict[c] ++;
        }
        bool count1 = false;
        int res = 0;
        for (auto x : dict) {
            if (!count1 && x.second % 2 == 1) {
                res ++;
                count1 = true;
            }
            res += (x.second / 2) * 2;
        }
        return res;
    }
}; 

 


int main()
{



    return 0;
}

