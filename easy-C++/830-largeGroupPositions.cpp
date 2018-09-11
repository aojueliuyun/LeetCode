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

// 2018.8.20

// leetcode 830 : largeGroupPositions


// solution : 
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int start = 0, end = 0;
        char cur = S[0];
        for (int i = 1; i < S.length(); i ++) {
            if (S[i] == cur) end = i;
            else {
                if (end-start+1 >= 3)
                    res.push_back({start, end});
                start = end = i;
                cur = S[i];
            }
        }
        if (end-start+1 >= 3)
            res.push_back({start, end});
        return res;
    }
};


int main()
{



    return 0;
}

