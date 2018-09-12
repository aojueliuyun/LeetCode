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

// 2018.7.23

// leetcode 290 wordPattern 

// key point : how to split a string to a list of strings
// use string::substr ----> string substr (size_t pos = 0, size_t len = npos) const;



// solution 1 : use hash map  ----------> 
// time: O(n)
// space; O(n)
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // split str to strings by space
        vector<string> vec;
        int pos = 0, rpos = str.find(' ');
        while (rpos != string::npos) { // string::npos is the max value of string::size_type, usually indicates not found
            if (rpos != pos)
                vec.push_back(str.substr(pos, rpos-pos));
            pos = rpos + 1;
            rpos = str.find(' ', pos);
        }
        if (pos != str.length())
            vec.push_back(str.substr(pos));

        // judge mathch or not
        if (pattern.length() != vec.size()) return false;
        unordered_map<char, string> cTos;
        unordered_map<string, char> sToc;
        for (int i = 0; i < pattern.length(); i ++) {
            auto citer = cTos.find(pattern[i]);
            auto siter = sToc.find(vec[i]);
            if (citer != cTos.end()) {     // found
                if (citer->second != vec[i] || siter == sToc.end() || siter->second != pattern[i]) // not match
                    return false;
            }
            else if (siter != sToc.end()) return false;
            else {   // not found
                cTos[pattern[i]] = vec[i];
                sToc[vec[i]] = pattern[i];
            }
        }
        return true;
    }
};


// solution 2 : just simplify the writing of solution 1
class Solution2 {
public:
    bool wordPattern(string pattern, string str) {
       
    }
};





int main()
{



    return 0;
}

