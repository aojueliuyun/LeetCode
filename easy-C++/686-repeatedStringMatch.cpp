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

// 2018.8.5

// leetcode 686 : repeatedStringMatch /  ÖØ¸´µþ¼Ó×Ö·û´®Æ¥Åä


// solution : simulation and match
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int lenA = A.length(), lenB = B.length();
        string tmp(A);
        while (tmp.length() < lenB+lenA) tmp += A;
        for (int i = 0; i < lenA; i ++) {
            if (tmp.substr(i, lenB) == B) {
//                return tmp.length() / lenA - (tmp.length()-i-lenB) / lenA;
                return (i + lenB + lenA - 1) / lenA;
            }
        }
        return -1;
    }
};


int main()
{
    string A = "abcd", B = "cdabcdab";
    Solution S;
    cout << S.repeatedStringMatch(A, B) << endl;


    return 0;
}

