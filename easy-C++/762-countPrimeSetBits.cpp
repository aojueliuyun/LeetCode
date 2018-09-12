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

// 2018.8.17

// leetcode 762 : countPrimeSetBits


// solution : traverse, judge and count
// time: O(nlogn) -------> n for traversal, logn for finding the number of 1
// execution time : 72 ms ---> exceed 4.31%
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for (int i = L; i <= R; i ++) {
            int n = i, count = 0;
            while (n) {
                if (n & 1) count ++;
                n >>= 1;
            }
            if (primes.count(count)) res ++;
        }
        return res;
    }
};


// solution 2 : use GCC built-in function to count the number of 1  ||  __builtin_popcount(val)
class Solution2 {
public:
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        
        while(L <= R) {
            int bitCount = __builtin_popcount(L);
            count += (665772 >> bitCount) & 1;        // what does the 665772 mean ? 
            ++L;
        }
        return count;
    }
};


int main()
{



    return 0;
}

