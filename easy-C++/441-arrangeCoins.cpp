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
#include<bitset>
#include<unordered_map>
using namespace std;

// 2018.7.26

// leetcode 441 : arrangeCoins


// solution : use formula
class Solution {
public:
    int arrangeCoins(int n) {
        return int((sqrt(1.0 + 8.0*n) - 1) / 2);
    }
};




int main()
{



	return 0;
}

