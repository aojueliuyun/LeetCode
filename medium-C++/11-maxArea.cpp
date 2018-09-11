#include<iostream>
#include<fstream>
#include<sstream>
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

// 2018.8.30

// leetcode 11 : maxArea


// solution 1 : brute-force
// time : O(n^2)
// execution time : 1316 ms
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0; i < height.size()-1; i ++) {
            for (int j = i+1; j < height.size(); j ++) {
                res = max(res, min(height[i], height[j]) * (j-i));
            }
        }
        return res;
    }
}; 


// solution 2 : two pointers
// time : O(n)
// execution time : 16 ms
class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int res = 0;
        while (l < r) {
            int h;
            if (height[l] > height[r]) {
                h = height[r];
                r --;
            }
            else {
                h = height[l];
                l ++;
            }
            res = max(res, h*(r-l+1)); // r or l already change, must plus 1
            
        }
        return res;
    }
}; 


int main()
{



    return 0;
}

