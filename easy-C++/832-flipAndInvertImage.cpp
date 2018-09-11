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

// 2018.8.20

// leetcode 832 : flipAndInvertImage


// solution : std::rercerse()
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (vector<int> & vec : A) {
            reverse(vec.begin(), vec.end());
            for (int & x : vec) {
                x ^= 1;
            }
        }
        return A;
    }
};



int main()
{



    return 0;
}

