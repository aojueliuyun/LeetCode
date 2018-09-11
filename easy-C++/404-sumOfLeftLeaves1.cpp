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

// 2018.7.24

// leetcode 404 sumOfLeftLeaves / 计算给定二叉树的所有左叶子之和


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// solution : recursion / BFS (use queue)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left && root->left->left == nullptr && root->left->right == nullptr)
            return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};


// solution 2 : use queue to BFS -------------> not right || ------> to be continued ... 2018.7.24
class Solution2 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode *> Q;
        Q.push(root);
        int sum = 0;
        while (!Q.empty()) {
            TreeNode * cur = Q.front();
            Q.pop();
            if (cur == nullptr) continue;
            else if (cur->left && cur->left->left == nullptr && cur->left->right == nullptr) {
                sum += cur->left->val;
                Q.push(cur->right);
            }
            else {
                Q.push(cur->left);
                Q.push(cur->right);
            }
        }
        return sum;
    }
};
 

int main()
{



    return 0;
}

