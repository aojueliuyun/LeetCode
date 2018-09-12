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
#include<bitset>
#include<unordered_map>
using namespace std;

// 2018.7.28

// leetcode 455 : findContentChildren 

// strategy : greedy

// solution : 
// time : O(nlogn) for sort and O(m+n) for match
// space :  O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.size() == 0 || s.size() == 0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        for (int i = 0, j = 0; i < g.size() && j < s.size(); ) {
            if (s[j] >= g[i]) {
                count ++;
                i ++;
                j ++;
            }
            else j ++;
        }
        return count;
    }
};

 


int main()
{
    vector<int> g{1,2,3}, s{1,2,2,4};
    Solution S;
    cout << S.findContentChildren(g, s) << endl; 


    return 0;
}

