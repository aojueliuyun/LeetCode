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

// 2018.7.24

// leetcode 303 : sumRange / 求数组一个范围内的和

// solution 1 : initial with a vector and get sum when call sumRange
// sumRange time: O(j-i+1)
class NumArray {
private:
    vector<int> array;
public:
    NumArray(vector<int> nums) : array(nums) {
        
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; k ++) sum += array[k];
        return sum;
    }
};

// solution 2 : save sum in data structrue (a vector)
// sumRange time: O(1)
class NumArray2 {
private:
    vector<int> sum;
public:
    NumArray2(vector<int> nums) {
        int tmp = 0;
        for (int i = 0; i < nums.size(); i ++) {
            tmp += nums[i];
            sum.push_back(tmp);
        }
    }
    int sumRange(int i, int j) {
        if (i == 0) return sum[j];
        else return sum[j] - sum[i-1];
    }
};



int main()
{



    return 0;
}

