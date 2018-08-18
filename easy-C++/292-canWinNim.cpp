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

// leetcode 292  Nim Game


// solution 1 : rcursion ---------> tow slow 
class Solution {
public:
    bool canWinNim(int n) {
        if (n < 4) return true;
        return ! (canWinNim(n-1) && canWinNim(n-2) && canWinNim(n-3));
    }
};


// solution 2 : find the law
class Solution2 {
public:
	bool canWinNim(int n) {
		return n % 4 != 0;
	}
}; 



int main()
{
	int n;
	Solution2 S;
	while (cin >> n) {
		for (int i = 1; i <= n; i ++) {
			if (S.canWinNim(i)) cout << i << ' ';
		}
		cout << endl;
//		if (S.canWinNim(n)) cout << "You can win !" << endl;
	}


	return 0;
}

