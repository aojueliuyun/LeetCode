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

// 2018.8.4

// leetcode 669 : trimBST / ÐÞ¼ô¶þ²æËÑË÷Ê÷


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// solution : just recursion 
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root) {
        	if (root->val > R) {
        		return trimBST(root->left, L, R);
			}
			else if (root->val < L) {
				return trimBST(root->right, L, R);
			}
			else {
				root->left = trimBST(root->left, L, root->val);
				root->right = trimBST(root->right, root->val, R);
				return root;
			}
		}
		else return nullptr;
    }
}; 


int main()
{



	return 0;
}

