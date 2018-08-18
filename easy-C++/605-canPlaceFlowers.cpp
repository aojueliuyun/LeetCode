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

// 2018.7.30

// leetcode 605 : canPlaceFlowers / 种花问题 


// solution : get the max number of the position than can insert
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    	if (flowerbed.size() == 0) return 0;
        int count0 = 0, sum = 0;
    	int i = 0;
    	while (flowerbed[i] == 0 && i < flowerbed.size()) { // avoid index out of bounds
    		count0 ++;
    		i ++;
		}
    	if (i == flowerbed.size())
    		sum += (count0+1) / 2; 
    	else sum += count0 / 2;
    	count0 = 0;
    	while (i < flowerbed.size()) {
    		if (flowerbed[i] == 0) {
    			count0 ++;
			}
			else {
				sum += (count0-1) / 2;
				count0 = 0;
			}
			i ++;
		}
		sum += count0/2;
		return sum >= n; 
    }
};



int main()
{
	vector<int> test{0};
	Solution S;
	cout << S.canPlaceFlowers(test, 1) << endl;


	return 0;
}

