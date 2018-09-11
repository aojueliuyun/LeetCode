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

// 2018.7.30

// leetcode 617 : mergeTrees / ºÏ²¢¶þ²æÊ÷


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution : recursion || construct a new tree, do not change t1 & t2
// execution time : 56 ms
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return nullptr;
        else if (t1 == nullptr || t2 == nullptr) {
            TreeNode * tmp = new TreeNode(0);
            if (t1) {
                tmp->val = t1->val;
                tmp->left = mergeTrees(t1->left, nullptr);
                tmp->right = mergeTrees(t1->right, nullptr);
            }
            if (t2) {
                tmp->val = t2->val;
                tmp->left = mergeTrees(t2->left, nullptr);
                tmp->right = mergeTrees(t2->right, nullptr);
            }
            return tmp;
        }
        else {
            TreeNode * tmp = new TreeNode(t1->val + t2->val);
            tmp->left = mergeTrees(t1->left, t2->left);
            tmp->right = mergeTrees(t1->right, t2->right);
            return tmp;
        }
    }
}; 


// solution 2 : use t1 and t2 to construct a tree || I don't recommand it, just do a implementation !!!
// It will make three trees point to each other(like a net or graph), use the mergeed tree before destructing t1 & t2.
class Solution2 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        TreeNode * tmp = new TreeNode(t1->val + t2->val);
        tmp->left = mergeTrees(t1->left, t2->left);
        tmp->right = mergeTrees(t1->right, t2->right);
        return tmp;
    }
}; 


int main()
{



    return 0;
}

