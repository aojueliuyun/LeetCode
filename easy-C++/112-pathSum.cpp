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

// leetcode 112 :  path sum 路径总和，
// 判断一棵树中是否有从根节点到叶子节点的路径，其路径上节点值总和为输入数值 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// solution 1 : traverse all paths of the tree
// time: O(n * m)  n -> leaf node number  m -> average length of all paths
class Solution {
public:
    bool hasPathSum(TreeNode * root, int sum) {
    	if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) {
        	if (root->val == sum) return true;
        	else return false;
		}
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

// solution 2 : ---------> DFS  depth first search    ========> same thing , ignore
class Solution2 {
public:
    bool hasPathSum(TreeNode * root, int sum) {
    	
	}
};



int main()
{



	return 0;
}

