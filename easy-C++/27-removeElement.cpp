#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<unordered_map>
using namespace std;


// 2018.7.15

// 27 remove Element
// iterator 就是好用 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        auto temp = nums.begin();
        for (auto iter = nums.begin(); iter != nums.end(); iter ++) {
        	if (* iter != val) {
        		* temp = * iter;
        		temp ++;
			}
		}
		return temp - nums.begin();
    }
};


int main()
{



	return 0;
}

