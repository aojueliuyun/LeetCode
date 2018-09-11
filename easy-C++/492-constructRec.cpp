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

// 2018.7.28

// leetcode 492 : constructRec / 给定面积，构造矩形，要求长>=宽，且长和宽之间差尽可能小 


// solution : traverse
class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res;
        for (int w = floor(sqrt(area)); w >= 1; w --) {
            if (area % w == 0) {
                res.push_back(area/w);
                res.push_back(w);
                return res;
            }
        }
        return {0, 0};
    }
};
 

int main()
{



    return 0;
}

