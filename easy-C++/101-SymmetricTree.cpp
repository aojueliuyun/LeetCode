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

// leetcode 101 : Symmetric Tree 
 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution : 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return symmetric(root->left, root->right);
    }
    bool symmetric(TreeNode *p, TreeNode *q) {
        if (p == NULL || q == NULL)
            return p == q;
        return (p->val == q->val) && symmetric(p->left, q->right) && symmetric(p->right, q->left);
    }
};


int main()
{



    return 0;
}

