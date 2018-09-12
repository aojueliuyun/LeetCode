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
#include<bitset>
using namespace std;

// 2018.7.25

// leetcode 401 readBinaryWatch 



// solution : recursion to find combination of 0 & 1, just simulation
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> vec;
        string current = "";
        getNumber(10, num, vec, current);
        vector<string> res;
        for (auto x : vec) {
            string hour = x.substr(0,4), min = x.substr(4, 6);
            int h = 0, m = 0;
            for (auto c : hour) h = h*2 + (c-'0');
            for (auto c : min) m = m*2 + (c-'0');
            string temp; 
            if (h < 12) temp = to_string(h) + ':';
            else continue;
            if (m < 10) temp += '0' + to_string(m);
            else if (m < 60) temp += to_string(m);
            else continue;
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    void getNumber(int digit, int num1, vector<string> & vec, string current) {
        if (digit < num1) return;
        else if (digit == 0) vec.push_back(current);
        else {
            if (num1 > 0)
                getNumber(digit-1, num1-1, vec, current + '1');
            getNumber(digit-1, num1, vec, current + '0');
        }
    }
};



// solution 2 : use bitset in <bitset> ------------> bitset is so awesome !!
class Solution2 {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h=0; h < 12; h ++) {
            for (int m=0; m < 60; m ++) {
                if (bitset<10>((h<<6)+m).count() == num) {
                    res.push_back(to_string(h) + (m >= 10 ? ":":":0") + to_string(m));
                }
            }
        }    
        return res;
    }
};




template <typename T>
void printVec(vector<T> vec) {
    for (auto x : vec)
        cout << x << endl;
}


int main()
{
    Solution2 S;
    int num;
    while (cin >> num) {
        printVec(S.readBinaryWatch(num));
    }


    return 0;
}

