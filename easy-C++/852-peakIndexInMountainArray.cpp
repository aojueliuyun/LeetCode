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

// leetcode 852 : peakIndexInMountainArray


// solution : 
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for (int i = 1; i < A.size(); i ++) {
            if (A[i] > A[i-1]) continue;
            else return i-1;
        }
        return A.size()-1;
    }
};


int main()
{



    return 0;
}

