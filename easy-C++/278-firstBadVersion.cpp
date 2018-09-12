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

// leetcode 278 firstBadVersion 

int badversion;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
    if (version < badversion) return false;
    else return true;
}

// solution 1 : binary search
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        if (isBadVersion(left)) return left;
        while (left < right) {
            int mid = left + (right - left) / 2; // avoid out of bounds, also can use long long or unsigned int
            if (isBadVersion(mid)) right = mid;
            else left = mid;
            if (right - left == 1) return right;
        }
    }
};



int main()
{
    int n;
    Solution S;
    while (cin >> n >> badversion) {
        cout << S.firstBadVersion(n) << endl; 
    }


    return 0;
}

