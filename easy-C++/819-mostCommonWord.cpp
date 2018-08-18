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

// 2018.8.18

// leetcode 819 : mostCommonWord / 最常见的单词


// solution : 
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int lpos = 0, rpos = 0;
        unordered_map<string, int> dict;
        for (int i = 0; i < paragraph.length(); i ++) {
            while (i < paragraph.length() && !isalpha(paragraph[i])) i ++;
            lpos = i;
            while (i < paragraph.length() && isalpha(paragraph[i])) i++;
            rpos = i;
            string tmp;
            for (int j = lpos; j < rpos; j ++) {
                tmp += tolower(paragraph[j]); // upper to lower
            }
            if (!tmp.empty()) dict[tmp] ++;
        }
        int maxtimes = 0;
        string res;
        unordered_set<string> ban(banned.begin(), banned.end());
        for (auto x : dict) {
            cout << x.first << " : " << x.second << endl;
            if (!ban.count(x.first) && x.second > maxtimes) {
                maxtimes = x.second;
                res = x.first;
            }
        }
        return res;
    }
};



// solution 2 : use stringstream || header file : <sstream>
class Solution2 {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (auto & c : paragraph) {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> dict;
        istringstream iss(paragraph);
        string word;
        pair<string, int> res{"", 0};
        while (iss >> word) {
            if (!ban.count(word) && ++dict[word] > res.second) {
                res = {word, dict[word]};
            }
        }
        return res.first;
    }
};




int main()
{
    string para = "abc abc? abcd the jeff!";
    vector<string> ban{"abc", "abcd", "jeff"};
    Solution2 S;
    cout << S.mostCommonWord(para, ban) << endl; 


	return 0;
}

