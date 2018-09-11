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

// 2018.8.14

// leetcode 704 : Binary search / 二分查找模板


// solution : binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return -1;
    }
};

 


int main()
{



    return 0;
}

