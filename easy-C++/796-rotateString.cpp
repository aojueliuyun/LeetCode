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

// 2018.8.18

// leetcode 796 : rotateString / Ðý×ª×Ö·û´®


// solution : usd string::substr() & +
// time : O(n^2)
// execution time : 16 ms
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        if (A.empty() && B.empty()) {
            return true;
        }
        for (int i = 0; i < B.length(); i ++) {
            if (A == B) return true;
            A = A.substr(1) + A[0];
        }
        return false;
    }
};


// solution 2 : return A in B+B
class Solution2 {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
        return (B+B).find(A) != string::npos;
    }
};


int main()
{


	return 0;
}

