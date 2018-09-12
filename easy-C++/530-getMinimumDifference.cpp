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

// leetcode 530 : getMinimumDifference 


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution 0 : get every reault between father and son node ---------> wroung solution
class Solution_wroung {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root->left && root->right) {
            return min(getMin(root->left, root->val), getMin(root->right, root->val));
        }
        else if (root->left) {
            return getMin(root->left, root->val);
        }
        else return getMin(root->right, root->val);
    }
    int getMin(TreeNode * node, int val) {
        int minval = abs(val - node->val);
        if (node->left)
            minval = min(minval, getMin(node->left, node->val));
        if (node->right)
            minval = min(minval, getMin(node->right, node->val));
        return minval;
    }
};



// solution 1 : get in-order sequence, and find answer
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> seq;
        inTraverse(root, seq);
        int mindiff = abs(seq[0] - seq[1]);
        for (int i = 1; i < seq.size()-1; i ++) {
            mindiff = min(abs(seq[i+1] -  seq[i]), mindiff);
        }
        return mindiff;
    }
    void inTraverse(TreeNode * root, vector<int> & vec) {
        if (root == nullptr) return;
        inTraverse(root->left, vec);
        vec.push_back(root->val);
        inTraverse(root->right, vec);
    }
};



// solution 2 : just in-order traverse, do not need to get the sequence
class Solution2 {
public:
    int getMinimumDifference(TreeNode* root) {
        int last = -1, ans = INT_MAX;
        inOrder(root, last, ans);
        return ans;
    }
    void inOrder(TreeNode * p, int & last, int & ans) {
        if (p == nullptr) return;
        inOrder(p->left, last, ans);
        if (last != -1)
            ans = min(ans, p->val - last);
        last = p->val;
        inOrder(p->right, last, ans);
    }
};


int main()
{



    return 0;
}

