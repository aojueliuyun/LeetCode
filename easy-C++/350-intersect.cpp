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

// leetcode 350 intersect / 多重集的交集


// solution 1 : use std::multiset in <set> and std::set_intersection in <algorithm>
// execution time : 36 ms
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> A(nums1.begin(), nums1.end()), B(nums2.begin(), nums2.end());
        vector<int> C(nums1.size() + nums2.size());
        auto iter = set_intersection(A.begin(), A.end(), B.begin(), B.end(), C.begin());
        C.resize(iter-C.begin());
        return C;
    }
};


// solution 2 : use unordered_map to save the times of elements ------> easy and efficient
// execution time : 8ms
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for (auto x : nums1) dict[x] ++;
        for (auto x : nums2) {
        	if (dict[x]) {
        		res.push_back(x);
        		dict[x] --;
			}
		}
        return res;
    }
};


int main()
{



	return 0;
}

