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

// leetcode 110 isBalanced ÅÐ¶Ï¶þ²æÊ÷ÊÇ·ñÊÇÆ½ºâ¶þ²æÊ÷

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

// solution 1 : first get height -> balanced or not ? ------- recursive

class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	if(root == nullptr) return true;   // trying use nullptr 
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode * root) {
    	if (root == nullptr) return 0;
    	return max(height(root->left), height(root->right)) + 1;
	}
};



// solution 2 : get height, at the same time judge balance or not ? if not exit directly ------ recursive

class Solution2 {
public:
	int check(TreeNode * root) {
		if (root == nullptr) return 0;
		int l = check(root->left);
		int r = check(root->right);
		if (l == -1 || r == -1) return -1;
		if (abs(l - r) > 1) return -1;
		return max(l, r) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (check(root) == -1) return false;
		return true;
	}
};


int main()
{



	return 0;
}

