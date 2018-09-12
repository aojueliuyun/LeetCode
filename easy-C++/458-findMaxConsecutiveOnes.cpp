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

// leetcode 485 findMaxConsecutiveOnes 


// solution 1 : traverse and record 
// time: O(n)
// space : O(1)
// execution time : 80ms 
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, count = 0;
        for (auto x : nums) {
            if (x == 1) count ++;
            else {
                ans = max(ans, count);
                count = 0;
            }
        }
        return ans;
    }
};



int main()
{



    return 0;
}

