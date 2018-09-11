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

// 2018.7.28

// leetcode 475 : findRadius / ¹©Å¯Æ÷


// solution : find the min diatance to a heater for every house, the max will be the result
// time : O(nlogn) for sort , O(n) for traverse
// space : O(1)
// execution time : 60ms
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0, n = houses.size(), m = heaters.size();
        for (int i = 0, j = 0; i < n; i ++) {
            while (houses[i] > heaters[j] && j+1 < m) {
                j ++;
            }
            int mindis = abs(heaters[j] - houses[i]);
            if (j-1 >= 0) {
                mindis = min(mindis, houses[i] - heaters[j-1]);
            }
            ans = max(mindis, ans);
        }
        return ans;
    }
};



// solution 2 : same as solution 1 (a little bit difference) , just more elegant
class Solution2 {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int m = houses.size(), n = heaters.size();
        int res = 0;
        for (int i=0, j = 0; i < m; ++i)
        {
            int cur = houses[i];
            while (j < n-1 && abs(heaters[j+1]-cur) <= abs(heaters[j]-cur)) j++;
            res = max(res, abs(heaters[j]-cur));
        }
        return res;
    }
};



int main()
{
    vector<int> houses{282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
    vector<int> heaters{823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};
    Solution2 S;
    cout << S.findRadius(houses, heaters);
    // result : 161834419

    return 0;
}

