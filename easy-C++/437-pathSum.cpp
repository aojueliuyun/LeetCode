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

// 2018.7.26

// leetcode 437 : pathSum / �ڶ��������ҳ�·����Ϊ����ֵ��·������


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution : recursion
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        vector<int> vec;
        countPaths(root, vec, sum, count);
        return count;
    }
    void countPaths(TreeNode * root, vector<int> vec, int sum, int & count) {
    	if (root == nullptr) return;
    	for (auto & x : vec) {
    		x += root->val;
    		if (x == sum) count ++; 
		}
		if (root->val == sum) count ++;
		vec.push_back(root->val);
		countPaths(root->left, vec, sum, count);
		countPaths(root->right, vec, sum, count);
	}
};
 


int main()
{



	return 0;
}

