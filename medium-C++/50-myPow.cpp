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
#include<bitset>
#include<unordered_map>
using namespace std;

// 2018.7.27

// leetcode 50 : myPow / implemenyt Pow(x,n)


// solution : quick power
class Solution {
public:
    double myPow(double x, int n) {
    	bool neg = false;
    	unsigned long long m;
    	if (n < 0) {
    		neg = true;
    		m = abs(n);        // -n to n, -2^32 must be as a border to be considered.
		}
		else m = n;
        double ans = 1;
        while (m) {
        	if (m % 2 == 1) {
        		ans *= x;
			}
			x *= x;
			m /= 2;
		}
		return neg ? 1/ans : ans;
    }
};


// solution 2 : use std::pow(x, n)
class Solution2 {
public:
    double myPow(double x, int n) {
    	return pow(x, n);
    }
};


// solution 3 : simplify solution 1
class Solution3 {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool neg = false;;
        if (n < 0) neg = true;
        while (n) {
        	if (n % 2 == 1 || n % 2 == -1) {
        		ans *= x;
			}
			x *= x;
			n /= 2;
		}
		return neg ? 1/ans : ans;
    }
};


// solution 4 : recursion
class Solution4 {
public:
    double myPow(double x, int n)
    {
        if (n == 0) return 1.0;
        double half = myPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else if (n % 2 == 1) {
            return half * half * x;
        } else {
            return half / x * half;
        }
    }
};


int main()
{
	cout << -1 % 2 << endl;
	double x;
	int n;
	Solution3 S;
	while (cin >> x >> n) {
		cout << S.myPow(x, n) << endl;
	}


	return 0;
}

