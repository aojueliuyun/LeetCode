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

// 2018.8.3

// leetcode 653 : findTarget / 两数之和 IV - 输入 BST


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// solution : traverse to get the sequence of tree nodes, and use hash map or set to search
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        traverse(root, vec);
        set<int> A;
        for (auto x : vec) {
            if (A.count(k-x)) return true;
            A.insert(x);
        }
        return false;
    }
    void traverse(TreeNode * root, vector<int> & vec) {
        if (root) {
            traverse(root->left, vec);
            vec.push_back(root->val);
            traverse(root->right, vec);
        }
    }
};


// solution 2 : recursion
class Solution2 {
public:
    unordered_set<int> S;
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr)
            return false;
        if (S.count(k - root->val))
            return true;
        S.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};


int main()
{
    


    return 0;
}

