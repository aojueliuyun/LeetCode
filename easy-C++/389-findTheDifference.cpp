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

// leetcode 389 findTheDifference


// solution : use hash map / unordered_map
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> ms, mt;
        for (auto c : s) ms[c] ++;
        for (auto c : t) mt[c] ++;
        for (auto x : mt) {
            if (ms[x.first] != x.second) return x.first;
        }
    }
};


// solution 2 : use xor 
class Solution2 {
public:
    char findTheDifference(string s, string t) {
        int d = 0;
        for (auto c : s+t) d ^= c;
        return char(d);
    }
};

 

int main()
{
    Solution S;
    string s, t;
    while (cin >> s >> t) {
        cout << S.findTheDifference(s, t) << endl;
    }


    return 0;
}

