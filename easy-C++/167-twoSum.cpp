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

// 2018.7.17

// leetcode 167 : find twoSum in ordered array


// solution 1 : traverse without thinking ---------> failed ------> TLE
// time: O(n^2)
// result: time limit exceed
// reason: without using the conditoin that input array is ordered !!
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for (int i = 0; i < numbers.size()-1; i ++)
            for (int j = i+1; j < numbers.size(); j ++)
                if (numbers[i] + numbers[j] == target)
                    return {i+1, j+1};
        return {}; 
    }
};


// solution 2 : use hash map -------------> AC
// time: O(n)
// space: O(n)
// run time: 16ms
class Solution2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> table;  // the first is the needed value, the second is index
        for (int i = 0; i < numbers.size(); i ++) {
            auto iter = table.find(numbers[i]);
            if (iter != table.end())
                return {iter->second+1, i+1};
            int needed = target - numbers[i];
            if (table.find(needed) == table.end())
                table[needed] = i;
        }
        return {};
    }
};

// solution 3 : two piointers ------------> AC
// time: O(n)
// space: O(1)
// run time: 4ms
class Solution3 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while (left < right) {
            int temp = numbers[left] + numbers[right];
            if (temp == target)
                return {left+1, right+1};
            else if (temp > target) right --;
            else left ++;
        }
        return {};
    }
}; 



// solution 4 : simlification from solution 3
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, j = numbers.size()-1; i < j; ) {
            if (numbers[i] + numbers[j] > target) j --;
            else if (numbers[i] + numbers[j] < target) i ++;
            else return {i+1, j+1};
        }
    }
};




void printVec(vector<int> v) {
    for (int x : v) cout << x << ' ';
    cout << endl;
}

int main()
{
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(10);
    Solution2 S;
    printVec(S.twoSum(vec, 9));
    
    

    return 0;
}

