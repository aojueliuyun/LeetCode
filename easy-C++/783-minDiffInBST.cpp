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
#include<unordered_set>
using namespace std;

// 2018.8.18

// leetcode 783 : minDiffInBST / 二叉搜索树结点最小距离



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// solution 1 :  
// execution time : 20 ms
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        if (root->left && root->right) {
        	return min(min(minDiffInBST(root->left), minDiffInBST(root->right)), min(root->val - maxVal(root->left), minVal(root->right) - root->val));
		}
		else if (root->left) {
			return min(root->val - maxVal(root->left), minDiffInBST(root->left));
		}
		else if (root->right) {
			return min(minVal(root->right) - root->val, minDiffInBST(root->right));
		}
 		else return INT_MAX;
    }
    int minVal(TreeNode * root) {
    	if (root->left)
    		return minVal(root->left);
		else
			return root->val;
	}
	int maxVal(TreeNode * root) {
		if (root->right) 
		   return maxVal(root->right);
		else 
			 return root->val;
	}
};



// solution 2 : save to a vector
// execution time : 0 ms
class Solution2 {
public:
    int minDiffInBST(TreeNode* root) {
       vector<int> seq;
       preTraverse(root, seq);
       int res = seq[1] - seq[0];
       for (int i = 1; i < seq.size()-1; i ++) {
	   	   res = min(res, seq[i+1] - seq[i]);
	   }
	   return res;
	}
	void preTraverse(TreeNode * root, vector<int> & seq) {
		if (root) {
			preTraverse(root->left, seq);
			seq.push_back(root->val);
			preTraverse(root->right, seq);
		}
	}
};

 

int main()
{



	return 0;
}

