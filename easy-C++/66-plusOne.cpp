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

// leetcode 66 : plus one

// 数组模拟整数 + 1


// solution 1 : just simulation
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 1 && digits[0] == 0) {
            digits[0] = 1;
            return digits;
        }
        for (int i = digits.size()-1; i >= 0; i --) {
            if (digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }
            else digits[i] = 0;
        }
        digits[0] = 1;
        digits.push_back(0); // two lines above --- euqals -->  digits.insert(digits.begin(), 1)
        return digits;
    }
};

 


int main()
{



    return 0;
}

