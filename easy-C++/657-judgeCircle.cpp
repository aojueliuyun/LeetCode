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

// 2018.8.3

// leetcode 657 : judgeCircle / ÅÐ¶ÏÂ·Ïß³ÉÈ¦

// overload operator + for pair<T,T>
template<typename T>
pair<T, T> operator+(pair<T, T> a, pair<T, T> b) {
    return {a.first + b.first, a.second + b.second};
}

// solution 1 : just simulation 
class Solution {
public:
    bool judgeCircle(string moves) {
        vector<pair<int, int>> d{{1,0}, {-1,0}, {0,1}, {0,-1}};
        pair<int, int> cur{0,0};
        for (auto ch : moves) {
            switch (ch) {
                case 'R' : cur = cur + d[0]; break;
                case 'L' : cur = cur + d[1]; break;
                case 'U' : cur = cur + d[2]; break;
                case 'D' : cur = cur + d[3]; break;
            }
        }
        if (cur == pair<int, int>{0,0}) return true; 
        else return false;
    }
};


// NOTES : We nned to see through the appearance to perceive the essence.

// soluiton 2 : simpler : just record how much every alphas the string have. 
class Solution2 {
public:
    bool judgeCircle(string moves) {
        int u, d, r, l;
        u = d = r = l = 0;
        for (auto ch : moves) {
            if (ch == 'U') u ++;
            if (ch == 'L') l ++;
            if (ch == 'D') d ++;
            if (ch == 'R') r ++;
        }
        return u == d && l == r;
    }
};




int main()
{


    return 0;
}

