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


// 2018.7.21

// leetcode 171 : titleToNumber excel的title转换为数字


// solution : decimal to Base 26 number
class Solution {
public:
    int titleToNumber(string s) {
    	int res = 0;
        for (char ch : s) {
        	res = res*26 + ch - 'A' + 1;
		}
		return res;
    }
};





int main()
{

	Solution S;
	string s;
	while (cin >> s) {
		cout << S.titleToNumber(s) << endl; 
	}


	return 0;
}

