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

// 2018.8.3

// leetcode 599 : findRestaurant


// solution : use hash map
// execution time : 592 ms ? why so slow ?
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> record;
        vector<string> res;
        int minIndexSum = INT_MAX;
        for (int i = 0; i < list1.size(); i ++) {
            record[list1[i]] += i+1;
        }
        for (int i = 0; i < list2.size(); i ++) {
            if (record[list2[i]] > 0) {
                int sum = i + record[list2[i]] - 1;
                if (sum < minIndexSum) {
                    minIndexSum = sum;
                    res.clear();
                    res.push_back(list2[i]);
                }
                else if (sum == minIndexSum) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
}; 



int main()
{



    return 0;
}

