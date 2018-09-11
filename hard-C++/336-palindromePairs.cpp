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

// 2018.9.9

// leetcode 336 : palindromePairs


// solution -1: brute-force ----------> of course TLE
class Solution_1 {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i ++) {
            for (int j = 0; j < words.size(); j ++) {
                string tmp = words[i] + words[j];
                if (i != j && isPalindrom(tmp)) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    bool isPalindrom(const string & str) {
        for (int i = 0, j = str.length() - 1; i < j; i ++, j --) {
            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }
};



// solution : use hash map
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> M    ;
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i ++) {
            M[words[i]] = i;
        }
        for (int i = 0; i < words.size(); i ++) {
            reverse(words[i].begin(), words[i].end());
            int len = words[i].size();
            for (int j = 0; j <= len; j ++) {
                string left = words[i].substr(0, j), right = words[i].substr(j);
                if (M.count(left) && isPalindrom(right) && M[left] != i) {
                    res.push_back({M[left], i});
                }
                if (M.count(right) && isPalindrom(left) && M[right] != i && j > 0) {  // j > 0 avoid duplicates
                    res.push_back({i, M[right]});
                }
            }
        }
        return res;
    }
    
    bool isPalindrom(string & str) {
        for (int i = 0, j = str.length() - 1; i < j; i ++, j --) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
};




int main()
{
    vector<string> test{"abcd","dcba","lls","s","sssll"};
    Solution S;
    vector<vector<int>> res = S.palindromePairs(test);
    for (auto vec : res) {
        for (auto x : vec) {
            cout << x << ", ";
        }
        cout << endl;
    }


    return 0;
}

