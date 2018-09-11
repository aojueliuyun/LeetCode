#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
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

// 2018.7.26

// leetcode 412 : fizzBuzz


// solution 
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i ++) {
            string temp;
            if (i % 3 == 0) temp += "Fizz";
            if (i % 5 == 0) temp += "Buzz";
            if (!temp.empty()) {
                res.push_back(temp);
                continue;
            }
            res.push_back(to_string(i));
        }
        return res;
    }
};



int main()
{



    return 0;
}

