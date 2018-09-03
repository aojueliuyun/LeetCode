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

// leetcode 22 : generateParenthesis
    

// solution : recursion
// notes : ensure left always <= right
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", n, n);
        return res;
    }
    void generate(vector<string> & res, string cur, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(cur);
            return;
        }
        if (left == 0) {
            generate(res, cur + ')', left, right - 1);
            return;
        }
        if (left < right) {
            generate(res, cur + ')', left, right - 1);
        }
        generate(res, cur + '(', left - 1, right);
    }
};



int main()
{
    Solution S;
    int n;
    while (cin >> n) {
        auto res = S.generateParenthesis(n);
        for (auto str : res) {
            cout << str << endl;
        }
        cout << endl;
    }


	return 0;
}

