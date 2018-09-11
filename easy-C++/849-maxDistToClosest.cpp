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

// 2018.8.21

// leetcode 849 : maxDistToClosest


// solution : just traverse and count the number of 0, left end and right end : dis = count, middle : dis = (count+1)/2
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int count = 0, res;
        for (int i = 0; seats[i] == 0; i ++) count ++;
        res = count;
        int cnt = 0;
        for (int i = count+1; i < seats.size(); i ++) {
            if (seats[i] == 0) cnt ++;
            else {
                res = max((cnt+1)/2, res);
                cnt = 0;
            }
        }
        res = max(cnt, res);
        return res;
    }
};


int main()
{



    return 0;
}

