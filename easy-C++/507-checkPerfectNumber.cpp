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
using namespace std;

// 2018.7.29

// leetcode 57 : checkPerfectNumber


// solution 
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = (num == 1 ? 0 : 1);
        int sq = floor(sqrt(num));
        for (int i = 2; i < sq; i ++) {
        	if (num % i == 0) {
        		sum += i + num/i;
			}
		}
		sum += (sq*sq==num && num!=1 ? sq : 0);
		return sum == num;
    }
};


int main()
{
	int n;
	Solution S;
	while (cin >> n) {
		cout << S.checkPerfectNumber(n) << endl;
	}


	return 0;
}

