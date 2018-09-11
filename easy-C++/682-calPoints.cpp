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

// 2018.8.4

// leetcode 682 : calPoints / ∞Ù«Ú±»»¸


// solution : just simulation
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0, value = 0;
        vector<int> score;
        for (auto s : ops) {
            if (s[0] >= '0' && s[0] <= '9') {
                value = 0;
                for (auto x : s) value = (x-'0') + value*10;
                sum += value;
                score.push_back(value);
            }
            else if (s[0] == '-') {
                value = 0;
                for (int i = 1; i < s.length(); i ++) {
                    value = (s[i] - '0') + value*10;
                }
                sum -= value;
                score.push_back(-value); 
            }
            else if (s == "+") {
                value = score[score.size()-1] + score[score.size()-2]; 
                sum += value;
                score.push_back(value);
            }
            else if (s == "D") {
                value = (score.empty() ? 0 : score.back()) * 2;
                sum += value;
                score.push_back(value);
            }
            else if (s == "C") {
                if (!score.empty()) {
                    sum -= score.back();
                    score.pop_back();
                }
            }
        }
        return sum;
    }
};


int main()
{
    vector<string> test{"-52","-92","-70", "C"};
    Solution S;
    cout << S.calPoints(test) << endl;

    return 0;
}

