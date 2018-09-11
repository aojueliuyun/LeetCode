#include<iostream>
#include<fstream>
#include<sstream>
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

// 2018.9.8

// leetcode 145 : postorderTraversal

// postorder traversal without recursion 


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



// solution : save last visited node as last, 
// if (p->right == null && last == p->left) || last == p->right  visit p
// else visit the children of p
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode * p = root, * last = root; // last can not be nullptr
        stack<TreeNode *> S;
        vector<int> res;
        if (p) S.push(p);
        while (!S.empty()) {
            p = S.top();
            if ((p->left == nullptr && p->right == nullptr) || (p->right == nullptr && last == p->left) || last == p->right) {
                res.push_back(p->val);
                S.pop();
                last = p;
            }
            else {
                if (p->right) S.push(p->right);
                if (p->left) S.push(p->left);
            }
        }
        return res;
    }
};



// solution 2 : kind tricky
// pust one node twice, if p == S.top(), then p hasn't been operated, push his children, else pop and visit.
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode * p = root;
        stack<TreeNode *> S;
        vector<int> res;
        if (p) {
            S.push(p);
            S.push(p);
        }
        while (!S.empty()) {
            p = S.top();
            S.pop();
            if(!S.empty() && p == S.top()) {
                if (p->right) {
                    S.push(p->right);
                    S.push(p->right);
                }
                if (p->left) {
                    S.push(p->left);
                    S.push(p->left);
                }
            }
            else {
                res.push_back(p->val);
            }
        }
        return res;
    }
}; 



int main()
{



    return 0;
}

