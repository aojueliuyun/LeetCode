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

// 2018.8.5

// leetcode 687 : longestUnivaluePath / 最长同值路径


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution : recursion
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int maxlen = 0;
        if (root) {
            dfs(root, maxlen);
            return maxlen;
        }
        else return 0;
    }
    // return to the max length of path from root
    int dfs(TreeNode * root, int & maxlen) {
        int l = 0, r = 0;
        if (root->left && root->val == root->left->val) {
            l = dfs(root->left, maxlen) + 1;
        }
        else if (root->left) {
            dfs(root->left, maxlen);
        }
        if (root->right && root->right->val == root->val) {
            r = dfs(root->right, maxlen) + 1;
        }
        else if (root->right) {
            dfs(root->right, maxlen);
        }
        maxlen = max(l+r, maxlen);
        return max(l, r);
    }
};




int main()
{



    return 0;
}

