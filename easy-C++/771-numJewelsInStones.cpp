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

// 2018.8.17

// leetcode 771 : numJewelsInStones


// solution : of course use hash set
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewel(J.begin(), J.end());
        int count = 0;
        for (auto c : S) {
            if (jewel.count(c)) count ++;
        }
        return count;
    }
};



int main()
{



    return 0;
}

