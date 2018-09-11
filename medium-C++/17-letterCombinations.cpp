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

// 2018.8.31

// leetcode 17 : letterCombinations


// solution : use iteration
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> dict{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> res;
        for (auto x : digits) {
            if (res.empty()) {
                for (auto c : dict[x])
                    res.push_back({c});
            }
            else {
                int n = res.size();
                for (int j = 1; j < dict[x].size(); j ++) {
                    for (int i = 0; i < n; i ++) {
                        res.push_back(res[i]);
                        res.back() += dict[x][j];
                    }
                }
                for (int i = 0; i < n; i ++) {  // first n strings
                    res[i] += dict[x][0];
                }
            }
        }
        return res;
    }
};


// solution 2 : use recursion
class Solution2 {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char, string> dict{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> res;
        dfs(digits, dict, 0, "", res);
        return res;
    }
    void dfs(string digits, unordered_map<char, string> dict, int level, string out, vector<string> & res) {
        if (level == digits.size()) res.push_back(out);
        else {
            string str = dict[digits[level]];
            for (auto c : str) {
                dfs(digits, dict, level + 1, out + c, res);
            }
        }
    }
};


int main()
{



    return 0;
}

