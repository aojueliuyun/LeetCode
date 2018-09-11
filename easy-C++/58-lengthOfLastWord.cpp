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

// leetcode 58: length Of Last Word
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        while (s[s.length() - 1] == ' ') {
            s = s.substr(0, s.length()-1);
        }
        for (int i = s.length() - 1; i >= 0; i --) {
            if (s[i] == ' ') {
                return s.length() - i - 1;
            }
        }
        return s.length();
    }
};


static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


int main()
{



    return 0;
}

