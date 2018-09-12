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

// leetcode 788 : rotatedDigits 



// solution : 
class Solution {
private:
    unordered_set<int> S1{0, 1, 8};
    unordered_set<int> S2{2, 5, 6, 9}; 
public:
    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i ++) {
            if (isGood(i)) count ++;
        }
        return count;
    }
    bool isGood(int n) {
        bool flag = false;
        while (n) {
            int tmp = n%10;
            if (!S1.count(tmp) && !S2.count(tmp)) 
                return false;
            else if (S2.count(tmp)) 
                flag = true;
            n /= 10;
        }
        return flag;
    } 
};
 


int main()
{
    


    return 0;
}

