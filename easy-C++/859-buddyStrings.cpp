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

// leetcode 859 : buddyStrings


// solution : 
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A == B) {
            if (A.length() > 26) { // exist at least one character whose number >= 2
                return true;
            }
            else {
                unordered_map<char, int> dict;
                for (auto c : A) {
                    if (++dict[c] > 1) return true;
                }
                return false;
            }
        }
        else {
            if (A.length() != B.length()) {
                return false;
            }
            int count = 0;
            vector<pair<char, char>> diff;
            for (int i = 0; i < A.length(); i ++) {
                if (A[i] != B[i]) {
                    diff.push_back({A[i], B[i]});
                    if (++count > 2) return false;
                }
            }
            if (diff[0].first != diff[1].second || diff[1].first != diff[0].second) return false;
            else return true;
        }
    }
};



int main()
{



	return 0;
}

