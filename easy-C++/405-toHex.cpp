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

// 2018.7.26

// leetcode 405 . decimal to hexadecimal / 10进制有符号整数转换为16进制 


// solution 
class Solution {
public:
    string toHex(int num) {
    	if (num == 0) return "0";
        unsigned int temp = num;         // unsigned int is useful !
        string res;
        while (temp > 0) {
        	unsigned int x = temp % 16;
        	temp /= 16;
        	res = char(x >= 10 ? 'a'+x-10 : '0'+x) + res; 
		}
		return res;
    }
};


int main()
{
	int num;
	Solution S;
	while (cin >> num) {
		cout << S.toHex(num) << endl;
	}


	return 0;
}

