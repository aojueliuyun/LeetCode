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

// 2018.8.30

// leetcode 12 : intToRoman


// solution : 
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> config{{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
        string res;
        int n = 1000;
        while (num) {
            int tmp = num / n;
            num %= n;
            if (tmp == 9) {
                res += {config[n], config[n*10]};
            }
            else if (tmp >= 5) {
                res += config[n*5];
                res.append(tmp-5, config[n]);
            }
            else if (tmp == 4) {
                res += {config[n], config[n*5]}; 
            }
            else if (tmp >= 1){
                res.append(tmp, config[n]);
            }
            n /= 10;
        }
        return res;
    }
};


// spped up
static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


int main()
{
    Solution S;
    int n;
    while (cin >> n) {
        cout << S.intToRoman(n) << endl;
    }


    return 0;
}

