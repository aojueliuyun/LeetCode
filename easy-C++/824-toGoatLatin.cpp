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

// leetcode 824 : toGoatLatin / É½ÑòÀ­¶¡ÎÄ


// solution :  stringstram is good
class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        istringstream iss(S);
        string word;
        int pos = 1;
        string res;
        while (iss >> word) {
            if (vowel.count(word[0])) {
                word += "ma";
            }
            else {
                word = word.substr(1) + word[0] + "ma";
            }
            word += string(pos, 'a');  // call : basic_string( size_type count, CharT ch, const Allocator& alloc = Allocator() );
            pos ++;
            res += word + ' ';
        }
        res.pop_back();
        return res;
    }
}; 


// solution 2 : use std::find()
class Solution2 {
public:
    string toGoatLatin(string S) {
        stringstream iss(S);
        string word;
        const string vowel = "aeiouAEIOU"; 
        string res;
        int pos = 1;
        while (iss >> word) {
            if (find(vowel.begin(), vowel.end(), word[0]) != vowel.end()) {
                word += "ma" + string(pos, 'a');
            }
            else {
                word = word.substr(1) + word[0] + "ma" + string(pos, 'a');
            }
            res += word + " ";
            pos ++;
        }
        res.pop_back();
        return res;
    }
}; 





int main()
{



    return 0;
}

