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

// 2018.7.17

// leetcode 122 : maxProfit 2 

// solution : use delta = prices[i] - prices[i-1] ----------> tricky
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int delta = prices[i] - prices[i-1];
            profit += delta > 0 ? delta : 0;
        }
        return profit;
    }
};

// solution 2 : maybe DP could work with O(n^2) time and space



int main()
{



    return 0;
}

