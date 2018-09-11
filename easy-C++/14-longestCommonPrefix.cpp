#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<array>
#include<numeric>
#include<unordered_map> 
using namespace std;

// 2018.7.15

// leetcode 14 : findPrefix || longest common prefix 


// solution 1 : 
class Solution {
public:
    string findPrefix(const string & s1, const string & s2) {
        string temp;
        for (int i = 0; i < s1.length() && i < s2.length(); i++) {
            if (s1[i] == s2[i]) 
                temp += s1[i];
            else break;
        }
        return temp;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return string();  // the case of zero element
        if (strs.size() == 1) return strs[0];  // the case of only one string 
        string temp{}, now{findPrefix(strs[0], strs[1])};
        for (int i = 1; i < strs.size()-1; i++) {
            temp = findPrefix(strs[i], strs[i+1]);
            if(temp != now) {
                now = temp.length() < now.length() ? temp : now;
            }
        }
        return now;
    }
};


// solution 2 :  same as solution 2
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res = strs[0];
        for (int i = 1; i < strs.size(); i ++) {
            res = LCP(res, strs[i]);
            if (res.empty()) break;
        }
        return res;
    }
    string LCP(string s, string t) {
        string res;
        if (s.length() < t.length()) swap(s, t);
        for (int i = 0; i < t.length(); i ++) {
            if (s[i] == t[i]) res += s[i];
            else break;
        }
        return res;
    }
}; 


int main()
{
    Solution S;
//    cout << S.findPrefix(string('pre'), string('prefix'));
    int n;
    vector<string> strs(n);
    cin >> n;
    cout << strs.size();
    for (int i=0; i < n; i ++) {
        string temp;
        cin >> temp;
        strs.push_back(temp);
    }

    cout << S.longestCommonPrefix(strs) << endl;

    return 0;
}

