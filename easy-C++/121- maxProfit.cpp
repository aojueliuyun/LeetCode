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

// 2018.7.16

// leetcode 121 : 买卖股票的最佳时机


// solution  1 : 暴力
// time: O(n*n) 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for (int i = 0; i < prices.size(); i ++) {
            for (int j = i+1; j < prices.size(); j ++) {
                if (prices[j] - prices[i] > max) {
                    max = prices[j] - prices[i];
                }
            }
        }
        return max;
    }
};

// solution 2 -------> just like two pointers, maintain max_profit & min_price
// O(n)
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min_price = prices[0];
        int max_profit = 0; 
        vector<int> profit(prices.size());
        for (int i = 1; i < prices.size(); i++) {
            max_profit = max(max_profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return max_profit;
    }
};



int main()
{



    return 0;
}

