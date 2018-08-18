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

// leetocde 326 isPowerOfThree / 判断一个数是否是3的mi


// solution 
class Solution {
public:
    bool isPowerOfThree(int n) {
    	if (n <= 0) return false;
        while (n%3 == 0) n /= 3;
        return n == 1;
    }
};

 

int main()
{



	return 0;
}

