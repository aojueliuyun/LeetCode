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

// 2018.8.14

// leetcode 728 : selfDividingNumbers / ×Ô³ýÊý


// solution 1 : 
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i ++) {
            if (selfDivide(i))
                res.push_back(i);
        }
        return res;
    }
    bool selfDivide(int x) {
        if (x == 0) return false;
        int num = x;
        while (x) {
            int a = x % 10;
            if (a == 0 || num % a != 0) return false;
            x /= 10;
        }
        return true; 
    }
};




int main()
{
    Solution S;
    int n;
    while (cin >> n) {
        vector<int> res = S.selfDividingNumbers(0, n);
        for (auto x : res) {
            cout << x << ", ";
        } 
        cout << endl;
    }


    return 0;
}

