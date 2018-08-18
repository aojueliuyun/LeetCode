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
using namespace std;


// 2018.7.29

// leetcode 566 : matrixReshape / æÿ’Û÷ÿÀ‹ (reshape) 


// notes: one of construtors of std::vector
//         vector (size_type n, const value_type& val,
//                 const allocator_type& alloc = allocator_type());



// solution : just read and write
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size(), column = nums.empty() ? 0 : nums[0].size();
        vector<vector<int>> res;
        if (row * column == r * c) {
        	res.resize(r);
        	for (auto & x : res) x.resize(c);   // must use reference &
			// vector<vector<int>> res(r, vector<int>(c, 0));   // -----> simpler
        	for(int i = 0; i < r*c; i ++) {
        		res[i/c][i%c] = nums[i/column][i%column];
			}
			return res;
		}
		else return nums;
    }
}; 


// print a matrix, for testing
template<typename T>
void printVec(vector<vector<T>> & nums) {
	int row = nums.size(), column = nums.empty() ? 0 : nums[0].size();
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < column; j ++) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	vector<vector<int>> test{{1,2}, {3,4}};
	Solution S;
	vector<vector<int>> res = S.matrixReshape(test, 4, 1);
	printVec(res);
	


	return 0;
}

