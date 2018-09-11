#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<unordered_map>
using namespace std;

// 2018.7.15

// leetcode 28 : count And Say


// solution : 
class Solution {
public:
    string countAndSay(int n) {
        string now("1"), pre;
        for (int i = 1; i < n; i ++) {
            pre = now;
            now = "";
            char pre_ch = pre[0];
            int count = 1;
            for (int j = 1; j < pre.length(); j ++) {
                if (pre[j] == pre_ch) {
                    count ++;
                }
                else {
                    now = now + to_string(count) + pre_ch;
                    pre_ch = pre[j];
                    count = 1;
                }
            }
            now = now + to_string(count) + pre_ch;
        }
        return now;
    }
};



int main()
{
    Solution S;
    int n;
    while (cin >> n) {
        cout << S.countAndSay(n) << endl;
    }
    return 0;
}

