#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cmath>
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

// 2018.7.28

// leetcode 458 : poorPigs / the old story the someone carzy makes pigs drink poison to judge which bucket is poison.


// solution : arrange buckets in several dimensions, the number of buckets of each colum is no nore than (minutesTotest / minutesToDie + 1)
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    	if (minutesToDie > minutesToTest) // can not acomplish the test
			return 0; 
		int res = 0, columns = minutesToTest / minutesToDie + 1;
		while (int(pow(columns, res)) < buckets) res ++;
		return res;
		// also can diretly use the formula
		// return ceil(log(buckets) / log(minutestToTest / minutesToDie + 1));
    }
};



int main()
{
	int n, md, mt;
	Solution S;
	while (cin >> n >> md >> mt) {
		cout << S.poorPigs(n, md, mt) << endl;
	}

	return 0;
}

