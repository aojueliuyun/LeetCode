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

// leetcode 20 : ÓÐÐ§À¨ºÅÆ¥Åä£¬


// Solution : use stack
// time: O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for (auto ch : s) {
            switch(ch) {
                case '(': case '[': case '{':
                    S.push(ch); break;
                case ')':
                    if (S.empty() || S.top() != '(') return false; // || ÅÐ¶ÏÇ°ÕßÎª1¼´Í£Ö¹ 
                    S.pop();
                    break;
                case '}':
                    if (S.empty() || S.top() != '{') return false;
                    S.pop();
                    break;
                case ']':
                    if (S.empty() || S.top() != '[') return false;
                    S.pop();
                    break;
            }
        }
        return S.empty();
    }
};


// solution 2 : simulate a stack manually 
class Solution2 {
public:
    bool isValid(string s) {
        int index = 0;
        for (int i = 0; i < s.size(); i++)
            switch (s[i]) {
                case '(': s[index++] = '('; break;
                case '[': s[index++] = '['; break;
                case '{': s[index++] = '{'; break;
                case ')': if (index == 0 || s[index - 1] != '(') return false; else --index; break;
                case ']': if (index == 0 || s[index - 1] != '[') return false; else --index; break;
                case '}': if (index == 0 || s[index - 1] != '{') return false; else --index; break;
            }
        return (index == 0);
    }
};
 

int main()
{
    


    return 0;
}

