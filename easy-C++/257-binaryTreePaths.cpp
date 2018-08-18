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

// 2018.7.23

// leetcode 257 binaryTreePaths / 求出二叉树的所有从根节点到叶子节点的路径



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
    vector<string> binaryTreePaths(TreeNode* root) {
    	vector<string> vec;
    	string path = "";
    	getTreePaths(root, path, vec);
        return vec; 
    }
    void getTreePaths(TreeNode * root, string path, vector<string> & vec) {
    	if (root == nullptr) return;
    	if (path.empty()) path += to_string(root->val);
    	else path += "->" + to_string(root->val);
    	if (root->left == nullptr && root->right == nullptr) {
    		vec.push_back(path);
    		return;
		}
		getTreePaths(root->left, path, vec);
		getTreePaths(root->right, path, vec);
	}
};




int main()
{



	return 0;
}

