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


// 2018.7.15

// leetcode 26 : removeDuplicates


// solution 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 0, temp = 0;
        if(!nums.empty()) temp = nums[0];
        else return 0;
        for (int i=1; i < nums.size(); i++) {
            if (nums[i] != temp) {
                temp = nums[i];
                nums[++p] = temp;
            }
        }
        return p + 1;
    }
}; 

int main()
{
    Solution S;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = S.removeDuplicates(nums);
    cout << "new length:" << ans << endl; 
    for (int i=0; i < ans; i++) {
        cout << nums[i] << ' ';
    }



    return 0;
}

