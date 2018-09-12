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

// 2018.7.29

// leetcode 551 : checkRecord

// solution
class Solution {
public:
    bool checkRecord(string s) {
        int numA = 0, numL = 0;
        char pre = 'x';
        for (auto c : s) {
            if (c == 'A') {
                numA ++;
                if (numA > 1) return false;
            }
            if (c == 'L') {
                if (pre == 'L') {
                    numL ++;
                    if (numL > 2) return false;
                }
                else numL = 1;
            }
            else numL = 0;
            pre = c; 
        }
        return true;
    }
};


// solution 2 : same as solution 1, just do not need the varaiable pre.
class Solution2 {
public:
    bool checkRecord(string s) {
        int numA = 0, numL = 0;
        for (auto c : s) {
            if (c == 'A') {
                numA ++;
                if (numA > 1) return false;
            }
            if (c == 'L') {
                numL ++;
                if (numL > 2) return false;
            }
            else numL = 0;
        }
        return true;
    }
};



int main()
{



    return 0;
}

