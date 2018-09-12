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

// 2018.7.27

// leetcode 3 : lengthOfLongestSubstring 


// solution 1 : brute-force attack / use hash table / array to judge duplicates
// result : hash table ------> time limit exceed --------> one last case didn't pass
//          C array ----------> 712 ms ------------------> barely pass
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int maxlength = 0;
        for (int i = 0; i < s.length(); i ++) {
            bool repeat = false;
            for (int j = i; j < s.length(); j ++) {
                int record[256];
                memset(record, 0, sizeof(int) * 256);
                for (int k = i; k <= j; k ++) {
                    if (record[s[k]] < 1) {
                        record[s[k]] ++;
                        maxlength = max(maxlength, k-i+1);
                    }
                    else {
                        repeat = true;
                        break;
                    }
                }
                if (repeat) break;
            }
        }
        return maxlength;
    }
}; 


// solution 2 : use two pointers i & j, record currenet sbustring, find if s[i] in the substring s[i:j], update i and maxlength.
// function called :  size_t find (char c, size_t pos = 0) const;
// execution time : 48 ms
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int maxlength = 1;
        int i = 0, j = 1;
        while (j < s.length()) {
            int pos = s.find(s[j], i);
            while (pos < j) {
                i = pos+1;
                pos = s.find(s[j], i);
            }
            maxlength = max(maxlength, j-i+1);
//            cout << i << ' ' << j << ' ' << maxlength << endl;
            j ++;
        }
        return maxlength;
    }
}; 





int main()
{
    string s;
    Solution S;
    while (cin >> s) {
        cout << S.lengthOfLongestSubstring(s) << endl;
    }


    return 0;
}

