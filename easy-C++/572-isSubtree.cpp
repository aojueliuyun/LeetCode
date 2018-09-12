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

// leetcode 572 : isSubtree 


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// solution 1 : just traverse to get all nodes. then judge equal
// time: worst O(|s|*|t|)  |s| for traverse, |t| for judging
// extra space: O(|s|)
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        vector<TreeNode *> snodes;
        traverse(s, snodes);
        for (auto sn : snodes) {
            if (subtree(sn, t)) return true;
        }
        return false;
    }
    void traverse(TreeNode * root, vector<TreeNode *> & vec) { // save all ndoes of a tree to a vector
        if (root) {
            traverse(root->left, vec);
            vec.push_back(root);
            traverse(root->right, vec);
        }
    }
    bool subtree(TreeNode * s, TreeNode * t) { // juege whether two trees equal
        if (s == nullptr && t == nullptr) return true;
        else if (s == nullptr || t == nullptr) return false;
        return s->val == t->val && subtree(s->left, t->left) && subtree(s->right, t->right);
    }
};



// solution 2 : do not need to get the vector of all nodes of s, judge equal when traversing. ------> simpler
// time: worst O(|s|*|t|)  |s| for traverse, |t| for judging
// space: O(|s|)
class Solution2 {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr) return false;
        return sameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t); 
    }
    bool sameTree(TreeNode * s, TreeNode * t) {
        if (s == nullptr && t == nullptr) return true;
        else if (s == nullptr || t == nullptr) return false;
        return s->val == t->val && sameTree(s->left, t->left) && sameTree(s->right, t->right);
    }
};




int main()
{



    return 0;
}

