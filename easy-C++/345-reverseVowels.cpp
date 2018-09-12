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
#include<unordered_map>
using namespace std;

// 2018.7.25

// leetcode 345 reverseVowels


// solution 1 : use a vector to save index of vowels
// time: O(n)
// space: O(m)       m is the number of vowels
class Solution {
public:
    string reverseVowels(string s) {
        vector<int> index;
        set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < s.length(); i ++) {
            if (vowels.count(s[i])) index.push_back(i);
        }
        for (int i = 0, j = index.size()-1; i < j; i ++, j --) {
            swap(s[index[i]], s[index[j]]);
        }
        return s;
    }
};

// solution 2 : do not use vector
class Solution2 {
public:
    string reverseVowels(string s) {
        set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0, j = s.length()-1;
        while (i < j) {
            if (vowels.count(s[i]) == 0) i++;
            else if (vowels.count(s[j]) == 0) j--;
            else swap(s[i++], s[j--]);
        }
        return s;
    }
};


int main()
{



    return 0;
}

