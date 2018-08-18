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

// 2018.8.18

// leetcode 806 : numberOfLines / 写字符串需要的行数


// solution : just simulation
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int count = 0, lines = 0;
        for (auto c : S) {
            if (count + widths[c-'a'] > 100) {
                lines ++;
                count = widths[c-'a'];
            }
            else count += widths[c-'a'];
        }
        return {lines+1, count};
    }
};




int main()
{



	return 0;
}

