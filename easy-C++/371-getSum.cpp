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

// leetcode 371 getSum 


// solution : use bit operation and recursion || ---> interesting
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        int sum = a ^ b;
        int carry = (a & b) << 1;
        return getSum(sum, carry);
    }
};

 

int main()
{
    int a, b;
    Solution S;
    while (cin >> a >> b) {
        cout << S.getSum(a, b) << endl;
    }

    return 0;
}

