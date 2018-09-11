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

// leetcode 100 : Same Tree 判断两颗树是否相同 



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// solution : recursive judge

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) 
            return p == q;
        else 
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
 


int main()
{



    return 0;
}

