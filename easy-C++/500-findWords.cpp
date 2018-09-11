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
using namespace std;

// 2018.7.28

// leetcode 500 : findWords 

// solution 1 : too long and has not a little bit elegance
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        set<char> line1{'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T', 'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'p', 'P'};
        set<char> line2{'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L'};
        set<char> line3{'z', 'Z', 'x', 'X', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm', 'M'};
        for (auto s : words) {
            if (s.empty()) continue;
            int in;
            if (line1.count(s[0])) in = 1;
            if (line2.count(s[0])) in = 2;
            if (line3.count(s[0])) in = 3;
            set<char> tmp;
            if (in == 1) tmp = line1;
            if (in == 2) tmp = line2;
            if (in == 3) tmp = line3;
            bool allin = false;
            for (auto c : s) {
                if (tmp.count(c)) allin = true;
                else {
                    allin = false;
                    break;
                }
            }
            if (allin) res.push_back(s);
        }
        return res;
    }
};


// solution 3 : use string::find rather than set::count
class Solution2 {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows({"qwertyuiop", "asdfghjkl", "zxcvbnm"});
        vector<string> ans;
        for (auto str : words) {
            for (int i = 0; i < 3; i++) {
                bool flag = true;
                for (auto c : str) {
                    if (c >= 'A' && c <= 'Z')
                        c = c - 'A' + 'a';
                    if (rows[i].find(c) == string::npos) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans.push_back(str);
                    break;
                }
            }
        }
        return ans;
    }
};


int main()
{



    return 0;
}

