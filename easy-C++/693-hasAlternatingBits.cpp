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

// 2018.8.13

// leetcode 693 : hasAlternatingBits / 交替位二进制数


// solution : 
class Solution {
public:
    bool hasAlternatingBits(int n) {
    	int pre = n%2;
    	n /= 2;
        while (n) {
        	if (n%2 == pre) 
        		return false;
        	pre = n%2;
        	n /= 2;
		}
		return true;
    }
};


int main()
{
	int n;
	Solution S;
	while (cin >> n) {
		cout << S.hasAlternatingBits(n) << endl;
	}


	return 0;
}

