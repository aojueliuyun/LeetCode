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

// leetcode 860 : lemonadeChange


// solution : greedy, if there is a 20, if has 10 : change 10+5 first, else change 5+5+5
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> money;
        for (int x : bills) {
            if (x == 5) money[5] ++;
            if (x == 10) {
                if (money[5] > 0) {
                    money[5] --;
                    money[10] ++;
                }
                else return false;
            }
            if (x == 20) {
                if (money[10] > 0) {
                    if (money[5] > 0) {
                        money[5] --;
                        money[10] --;
                        money[20] ++;
                    }
                    else return false;
                }
                else if (money[5] >= 3) {
                    money[5] -= 3;
                    money[20] ++;
                }
                else return false;
            }
        }
        return true;
    }
};
 


int main()
{



	return 0;
}

