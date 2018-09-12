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

// 2018.7.20

// leercode 168 : convertToTitle

// solution 1 : get bits of string ------> get every bit of string frontward ----------> result
// time: O(logn)
// space: O(logn)
// execution time: 8ms
class Solution {
public:
    string convertToTitle(int n) {
        vector<long long> log;
        log.push_back(0);
        for (long long mul = 1, sum = 0; sum <= 0xffffffff;) {
            mul *= 26;
            sum += mul;
            log.push_back(sum);
        }
        int bits = lower_bound(log.begin(), log.end(), n) - log.begin(); // the length of string
        string ans;
        int val = n - log[bits-1] - 1;
        for (int i = 0; i < bits; i ++) {
            char ch = val%26 + 'A';
            val /= 26;
            ans = ch + ans; 
        }
        return ans;
    }
};



// solution 2 : the substance of this question : Base 26 to decimal, without 0, n need to substract 1.
// time: O(logn)
// space: O(1)
// excution time : 0ms
class Solution2 {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n) {
            ans = char((n-1)%26 + 'A') + ans;
            n = (n-1) / 26;
        }
        return ans;
    }
};







template<typename T>
void printVec(vector<T> v) {
    for (int i = 0; i < v.size(); i ++) {
        cout << v[i] << endl;
    }
    cout << endl;
}


int main()
{
    Solution2 S;
    int n;
    while (cin >> n) {
        cout << S.convertToTitle(n) << endl;
    }


    return 0;
}

