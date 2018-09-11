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
#include<bitset>
#include<unordered_map>
using namespace std;

// 2018.7.27

// leetcode 4 : findMedianSortedArrays
// require : O(log(m+n)) time comlexity

// level : hard || my first hard question.


// solution 1 : brute-force attack || merge two arrays and find the median
// time : O(m+n)
// space : O(m+n)
// execution time : 52 ms
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                merge.push_back(nums1[i++]);
            else
                merge.push_back(nums2[j++]);
        }
        while (i < nums1.size())
            merge.push_back(nums1[i++]);
        while (j < nums2.size())
            merge.push_back(nums2[j++]);
        if (merge.size() % 2 == 0)
            return (merge[merge.size()/2] + merge[merge.size()/2-1]) * 0.5;
        else return merge[merge.size() / 2];
    }
};


// solution 2 : divide and conquer
// time : O(log(m+n))
// space : 
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};

int main()
{



    return 0;
}

