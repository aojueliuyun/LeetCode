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
using namespace std;

// 2018.7.29

// leetcode 543 : diameterOfBinaryTree


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution 1 : just recursion 
class Solution {
public:
    int diameterOfBinaryTree(TreeNode * root) {
        if (root == nullptr) return 0;
        int maxPathLen = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(maxDepth(root->left) + maxDepth(root->right), maxPathLen);
    }
    int maxDepth(TreeNode * root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};



int main()
{



    return 0;
}

