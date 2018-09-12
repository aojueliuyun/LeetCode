#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
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
#include<unordered_map>
using namespace std;

// 2018.7.23

// leetcode 264 : 


// solution : --------------> time limit exceed.  to be continued , Later
class Solution {
public:
    int nthUglyNumber(int n) {
        int cnt = 1, num = 1;
        while (cnt < n) {
            num ++;
            if (isUgly(num)) cnt ++;
        }
        return num;
    }
    bool isUgly(int num) {
        if (num < 1) return false;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }
};



int main()
{



    return 0;
}

