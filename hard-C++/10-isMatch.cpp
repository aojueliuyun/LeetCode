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

// 2018.8.28

// leetcode 10 : isMatch / regular expression mathching (* & .)

// algorithm : dp & back-track || If you are stuck, recursion is your friend.


// solution : recursion ----> neat and elegant
// execution time : 76 ms
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if ('*' == p[1]) {
            // * matches 0 times or more times
            return isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p);
        }
        else {
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
        }
    }
};


// solution 2 : DP ---------> to be continued
class Solution {
public:
    bool isMatch(string s, string p) {
        
    }
};



int main()
{



	return 0;
}

