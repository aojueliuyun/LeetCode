#include<iostream>
#include<fstream>
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

// leetcode 804 : uniqueMorseRepresentations


// solution : 
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> alpha{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> codes;
        for (auto str : words) {
            string tmp;
            for (auto c : str) {
                tmp += alpha[c-'a'];
            }
            codes.insert(tmp);
        }
        return codes.size(); 
    }
};



int main()
{



    return 0;
}

