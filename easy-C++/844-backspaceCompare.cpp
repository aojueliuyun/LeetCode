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

// 2018.8.21

// leetcode 844 : backspaceCompare


// solution : 
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string strs, strt;
        for (auto c : S) {
            if (c == '#') {
                if (!strs.empty())
                    strs.pop_back();
            }
            else strs += c;
        }
        for (auto c : T) {
            if (c == '#') {
                if (!strt.empty())
                    strt.pop_back();
            }
            else strt += c;
        }
        return strs == strt;
    }
};
 


int main()
{
    Solution S;
    cout << S.backspaceCompare("ab#c", "ad#c") << endl;


	return 0;
}

