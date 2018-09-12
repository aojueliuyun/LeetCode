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

// leetcode 263 missingNumber 


// solution : get ideal sum and substact actual sum
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long int sum = n*(n+1) / 2;
        for (auto x : nums) sum -= x;
        return sum;
    }
}; 

// solution 2 : use xor
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        for (int i=0; i <= n; i ++) ret ^= i;
        for (auto x : nums) ret ^= x;
        return ret;
    }
}; 


int main()
{



    return 0;
}

