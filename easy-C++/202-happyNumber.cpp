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

// 2018.7.21

// leetcode 202 : happy number 


// solution : use hash map or set to judge whether will be a infinite loop.
// time: How to calculate ? Avaerage ? Possibility ?
// execution time: 16ms
class Solution {
public:
    bool isHappy(int n) {
        set<int> Nums;
        Nums.insert(n);
        while (n != 1) {
            n = getNext(n);
            if (Nums.find(n) == Nums.end()) // equals to : Nums.count(x) ------> has return 1 else return 0 / return the number of x in NUms.
                Nums.insert(n);
            else return false;
        }
        return true;    
    }
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            sum += pow(n%10, 2);
            n /= 10;
        }
        return sum;
    }
};

// solution 2 : do not use hash map, because the the ends of the loop is certain which are 1 or 4, 1 is happy, 4 is not.
// question : How to find the end of this loop : print ouput form to find the principle for different inputs in a appropriate input sacle.
class Solution2 {
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        while (n != 1 && n != 4) {
            int sum = 0;
            while (n) {
                sum += pow(n%10, 2);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};





int main()
{
    Solution2 S;
    int n;
    while (cin >> n) {
        cout << S.isHappy(n) << endl;
    } 


    return 0;
}

