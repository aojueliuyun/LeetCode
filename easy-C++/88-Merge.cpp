#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<unordered_map>
using namespace std;

// 2018.7.16

// leetcode 88 合并两个排序数组 


// solution 1 : not in place merge
// time: O(m+n)
// space: O(m+n) 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	vector<int> temp;
    	int i = 0, j = 0;
		while (i < m && j < n) {
			temp.push_back(nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
		}
		while (i < m) temp.push_back(nums1[i++]);
		while (j < n) temp.push_back(nums2[j++]);
		for (i = 0; i < n+m; i++) nums1[i] = temp[i];
    }
};



// solution 2 : in-place merge , from the back to the front 
// time: O(m+n)
// space: O(1)
class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	int p1 = m-1, p2 = n-1, last = n+m-1;
    	while (p1 >=0 && p2 >= 0) {
    		nums1[last--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
		}
		while (p2 >= 0) nums1[last--] = nums2[p2--];
//		// optimazition to one loop
//		while (p2 >= 0) nums1[last--] = p1 >= 0 && nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
    }
};




// solution 3 : copy nums2 to the back of nums1, then sort
// time: O(m+n) / O((m+n)log(m+n))
// space: O(1)
class Solution3 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	for (int i = 0; i < n; i++) {
    		nums1[m+i] = nums2[i];
		}
		sort(nums1.begin(), nums1.end());
    }
};


int main()
{



	return 0;
}

