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

// leetcode 709 : toLowerCase


// solution 1 : 
class Solution {
public:
    string toLowerCase(string str) {
        string res;
        for (auto c : str) {
            res += tolower(c);
        }
        return res;
    }
};


// solution 2 : 
class Solution2 {
public:
    string toLowerCase(string str) {
        for (auto & c : str) {
            if (isupper(c))
                c = tolower(c);
        }
        return str;
    }
};



int main()
{
    Solution S;
    string s;
    while (cin >> s) {
        cout << S.toLowerCase(s) << endl;
    }


    return 0;
}

