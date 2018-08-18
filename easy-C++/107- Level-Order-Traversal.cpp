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

// 2018.7.18

// leetcode 107 : Level Order Traversal 树的层次遍历-----------> 借助队列实现 
// same as 102


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution : use queue
// time: O(N)  N -------> the number of nodes

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> V;
    	if (root == NULL) return V;
        queue<pair<TreeNode *, int>> Q;
        using P = pair<TreeNode *, int>;
        Q.push(P(root, 1));
        vector<int> vec;
        int level = 1;
        P temp;
        while(!Q.empty()) {
        	temp = Q.front();
        	Q.pop();
        	if (temp.second == level) 
				vec.push_back(temp.first->val);
			else {
				V.push_back(vec);
				vec = vector<int>();
				vec.push_back(temp.first->val);
				level ++;
			}
			if (temp.first->left != NULL) Q.push(P(temp.first->left, level + 1));
			if (temp.first->right != NULL) Q.push(P(temp.first->right, level + 1));
		}
		V.push_back(vec);
//		reverse(V.begin(), V.end());
		return V; 
    }
};



int main()
{



	return 0;
}

