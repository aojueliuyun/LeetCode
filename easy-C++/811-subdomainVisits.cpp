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

// leetcode 811 : subdomainVisits / 子域名访问计数


// solution :  use string::find(char ch, size_t pos) to split string  || also can compare character directly
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> dict;
        for (auto str : cpdomains) {
            int pos = str.find(' ');
            string tmp = str.substr(0, pos);
            int times = toVal(tmp);
            dict[str.substr(pos+1)] += times;
            pos = str.find('.', pos+1);
            while (pos != string::npos) {
                dict[str.substr(pos+1)] += times;
                pos = str.find('.', pos+1);
            }
        }
        vector<string> res;
        for (auto x : dict) {
            res.push_back(to_string(x.second) + ' ' + x.first);
        }
        return res;
    }
    int toVal(string & str) {
        int res = 0;
        for (auto c : str) {
            res = res * 10 + c - '0';
        }
        return res;
    }
};




int main()
{



	return 0;
}

