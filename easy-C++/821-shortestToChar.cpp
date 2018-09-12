#include<iostream>
#include<fstream>
#include<sstream>
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

// 2018.8.18

// leetcode 821 : shortestToChar


// solution : 
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> index;
        for (int i = 0; i < S.length(); i ++) {
            if (S[i] == C) index.push_back(i);
        }
        int left = -S.length(), right = index[0], pos = 0;
        vector<int> res;
        for (int i = 0; i < S.length(); i ++) {
            if (right < i) {
                left = right;
                if (pos+1 < index.size()) right = index[++pos];
                else right += 2 * S.length();
            }
            res.push_back(min(right-i, i-left));
        }
        return res;
    }
};


int main()
{



    return 0;
}

