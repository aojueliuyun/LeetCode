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

// leetcode 189 : rotate array 

// require: in-place, space:O(1)


// solution 1 : use vector::insert (iterator position, InputIterator first, InputIterator last)
// feture: not in-place
// time: not sure
// space : O(k)
// execution time : 28ms
class Solution {
public:
    void rotate(vector<int> & nums, int k) {
    	int size = nums.size();
    	k = k % size;
        nums.insert(nums.begin(), nums.end()-k, nums.end());
        nums.resize(size);
    }
};


// solution 2 : slice array into two subarrays, reverse them then reverse it back
// time: O(n)
// space: O(1)
// execution time: 16 ms
class Solution2 {
public:
    void rotate(vector<int> & nums, int k) {
    	int n = nums.size();
    	k = k % n;
    	reverseVector(nums, 0, n-k-1);
    	reverseVector(nums, n-k, n-1);
    	reverseVector(nums, 0, n-1);   // reverse it back
    }
    void reverseVector(vector<int> & nums, int i, int j) {
    	while (i < j) {
    		int temp = nums[i];
    		nums[i++] = nums[j];
    		nums[j--] = temp;
		}
	}
};


// solution 3 : same as solution 2, just use reverse(beginIter, endIter) ----------> attention: range-> [ beginIter, endIter )
class Solution3 {
public:
    void rotate(vector<int> & nums, int k) {
    	k = k % nums.size();   // essential
    	reverse(nums.begin(), nums.end()-k);
    	reverse(nums.end()-k, nums.end());
    	reverse(nums.begin(), nums.end());
	}
};



int main()
{

	return 0;
}

