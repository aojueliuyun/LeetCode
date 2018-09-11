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

// 2018.7.22

// leetocde 205 : isIsomorphic / 判断两个·字符串是否同构

// solution
// input : s and t has same length 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, char> M;    // here also can use C array, vector, etc. because there's just 256 chars.
        map<char, char> B;
        for (int i=0; i < s.length(); i ++) {
            if (M.find(s[i]) == M.end()) {
                M[s[i]] = t[i];
                if (B.find(t[i]) == B.end()) B[t[i]] = s[i];
                else if (B[t[i]] != s[i]) return false;    // tow chars map to a same char
            }
            else if (M[s[i]] == t[i]) continue;
            else return false; // one char map to two different chars
        }
        return true;
    }
}; 


// solution2 : same as solution 1
class Solution2 {
public:
    bool isIsomorphic(string s, string t) {
        int sTot[256], tTos[256];
        memset(sTot, -1, sizeof(int)*256);
        memset(tTos, -1, sizeof(int)*256);
        for (int i=0; i < s.length(); i ++) {
            if (sTot[s[i]] == -1) sTot[s[i]] = t[i];
            if (tTos[t[i]] == -1) tTos[t[i]] = s[i];
            if (sTot[s[i]] != t[i] || tTos[t[i]] != s[i]) return false;
        }
        return true;
    }
}; 


int main()
{
    string s,t;
    Solution S;
    while (cin >> s >> t) {
        cout << S.isIsomorphic(s, t) << endl; 
    }


    return 0;
}

