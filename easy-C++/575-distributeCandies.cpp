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

// 2018.7.30

// leetcode 575 : distributeCandies


// solution : use hash table / set to get the number of kinds of candies
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> kinds(candies.begin(), candies.end());
        return min(kinds.size(), candies.size() / 2);
    }
};


int main()
{



    return 0;
}

