#include<iostream>
#include<fstream>
#include<sstream>
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

// 2018.8.30

// leetcode 6 : convert


// solution : just simulation
// time : O(n)
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> vec(numRows);
        int index = 0;
        bool plus = true;
        for (auto c : s) {
            vec[index] += c;
            if (index == numRows - 1) plus = false;
            if (index == 0) plus = true;
            if (plus) index ++;
            else index --;
        }
        string res;
        for (auto str : vec) {
            res += str;
        }
        return res;
    }
}; 


int main()
{



	return 0;
}

