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

// 2018.7.24

// leetcode 274 guessNumber 

int mynumber = 0;
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num){
    if (num > mynumber) return -1;
    else if (num == mynumber) return 0;
    else return 1;
}

// solution : just call the API and use binary search
class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) return mid;
            else if (res == -1) right = mid-1;
            else left = mid+1;
        }
        return 0;
    }
};


int main()
{
    int n;
    Solution S;
    while (cin >> n >> mynumber) {
        cout << S.guessNumber(n) << endl;
    }    



    return 0;
}

