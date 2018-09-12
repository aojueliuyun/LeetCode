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

// leetcode 784 : letterCasePermutation 


// solution : recursion
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<int> index;
        for (int i = 0; i < S.length(); i ++) {
            if (isalpha(S[i])) index.push_back(i);
        }
        vector<string> res;
        get(res, S, index, 0, index.size());
        return res;
    }
    void get(vector<string> & res, string S, const vector<int> & index, int i, int j) {
        if (i == j) {
            res.push_back(S);
        }
        else if (i < j) {
            S[index[i]] = tolower(S[index[i]]);
            get(res, S, index, i+1, j);
            S[index[i]] = toupper(S[index[i]]);
            get(res, S, index, i+1, j);
        }
    }
};


// solution 2 : iteration
class Solution2 {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res{""};
        for (auto c : S) {
            int len = res.size();
            if (c >= '0' && c <= '9') {
                for (auto & str : res) str += c;
            }
            else {
                for (int i = 0; i < len; i ++) {
                    res.push_back(res[i]);
                    res[i] += c;
                    res[len+i] += (c ^ 32);   // 'A' - 'a' = 32
                }
            }
        }
        return res;
    }
};



int main()
{
    Solution2 S;
    string test;
    vector<string> res;
    while (cin >> test) {
        res = S.letterCasePermutation(test);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << endl;
    }
    

    return 0;
}

