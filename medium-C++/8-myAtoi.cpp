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

// leetcode 8 : myAtoi / ×Ö·û´®×ªÕûÊý


// solution : just simulation
class Solution {
public:
    int myAtoi(string str) {
    	if (str.empty()) return 0;
    	int i = 0;
    	bool neg = false; 
    	while (i < str.length() && str[i] == ' ') i ++;
    	if (i == str.length()) {
    		return 0;
		}
    	if (str[i] == '+') {
    		neg = false;
    		i ++;
		}
		else if (str[i] == '-') {
			neg  = true;
			i ++;
		}
		else if (str[i] < '0' || str[i] > '9') {
			return 0;
		}
		long long ans = 0;
		while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
			ans = ans * 10 + str[i] - '0';
			if (neg && -ans < INT_MIN) return INT_MIN;
			if (!neg && ans > INT_MAX) return INT_MAX;
			i ++;
		}
		return neg ? -ans : ans;
    }
}; 




int main()
{
	string s;
	Solution S;
	while (cin >> s) {
		cout << S.myAtoi(s) << endl;
	}


	return 0;
}

