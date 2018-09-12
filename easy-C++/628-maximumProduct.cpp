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

// leetcode 628 : maximumProduct


// solution : maintain 5 values : firstmin, secondmin, firstmax, secondmax, thirdmax  || this five names is too long, isn't it ?
// time: O(n)  ---------> search problem
// space: O(1) 
// execution time : 40 ms
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int firstmin = INT_MAX, secondmin = INT_MAX, firstmax = INT_MIN, secondmax = INT_MIN, thirdmax = INT_MIN;
        for (auto x : nums) {
            if (x >= firstmax) {
                thirdmax = secondmax;
                secondmax = firstmax;
                firstmax = x;
            }
            else if (x >= secondmax) {
                thirdmax = secondmax;
                secondmax = x;
            }
            else if (x >= thirdmax) {
                thirdmax = x;
            }
            if (x <= firstmin) {
                secondmin = firstmin;
                firstmin = x;
            }
            else if (x <= secondmin) {
                secondmin = x;
            }
        }
        cout << firstmin << secondmin << endl;
        cout << firstmax << secondmax << thirdmax << endl; 
        return max(firstmin*secondmin*firstmax, firstmax*secondmax*thirdmax);
    }
}; 


// solution 2 : just sort and get the five values
// time: O(nlogn)
// space: O(1)
// execution time : 68 ms
class Solution2 {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums.back(), nums.back() * (*(nums.end()-2)) * (*(nums.end()-3)));
    }
}; 



int main()
{
    vector<int> test{-1,-2,-3};
    Solution2 S;
    cout << S.maximumProduct(test) << endl;


    return 0;
}

