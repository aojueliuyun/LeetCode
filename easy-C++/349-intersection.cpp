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

// leetcode 349 intersection / 求两个vector交集


// solution 1 : use std::set and std::set_intersection (in <algorithm>)
// time: O(n^2)
// space: O(|nums1| + |nums2|)
// exexution time: 12ms
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> A(nums1.begin(), nums1.end()), B(nums2.begin(), nums2.end());
        vector<int> C(nums1.size() + nums2.size());
        auto iter = set_intersection(A.begin(), A.end(), B.begin(), B.end(), C.begin());
        C.resize(iter-C.begin());
        return C;
    }
};

// solution 2 : use std::find in <alforithm> to search.
// time: O(n^2) 
// execution time: 20ms
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> res;
    	for (int i = 0; i < nums1.size(); i ++) {
    		if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end() && find(res.begin(), res.end(), nums1[i]) == res.end())
    			res.push_back(nums1[i]);
		}
		return res;
    }
};

// solution 3 : use set and not use std::find in <algorithm>
// execution time: 4ms
class Solution3 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	set<int> numset;
    	for (auto x : nums1) numset.insert(x);
    	vector<int> res;
    	for (auto x : nums2) {
    		if (numset.count(x)) {
    			res.push_back(x);
    			numset.erase(x);
			}
		}
		return res;	
    }
};



int main()
{



	return 0;
}

