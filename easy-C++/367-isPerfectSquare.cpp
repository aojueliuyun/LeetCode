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
#include<cmath>
using namespace std;

// 2018.7.24

// leetcode 367 isPerfectSquare 

// solution 
class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = sqrt(num);
        return x*x == num; 
    }
};

 

int main()
{



    return 0;
}

