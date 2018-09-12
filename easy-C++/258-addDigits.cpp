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

// leetcode 258 : addDigits 
// require: time O(1)

// solution : find the regular pattern
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1)  % 9;
    }
};



int main()
{
    cout << -1 % 9 << endl;


    return 0;
}

