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

// leetcode 606 : tree2str / 根据二叉树创建字符串



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// solution : jsut recursion
class Solution {
public:
    string tree2str(TreeNode* t) {
        string res;
        treeToStr(t, res);
        return res;
    }
    void treeToStr(TreeNode * t, string & s) {
        if (t) {
            s += to_string(t->val);
            if (t->left) {
                s += "(";
                treeToStr(t->left, s);
                s += ")";
            }
            else if (t->right) s += "()";
            if (t->right) {
                s += "(";
                treeToStr(t->right, s);
                s += ")";
            }
        }
    }
};


// solution 2 : do not need another method for help
class Solution2 {
public:
    string tree2str(TreeNode* t) {
        string res;
        if (t) {
            res += to_string(t->val); 
            if (t->left) res += '(' + tree2str(t->left) + ')';
            else if (t->right) res += "()";
            if (t->right) res += '(' + tree2str(t->right) + ')';
        }
        return res;
    }
};



int main()
{



    return 0;
}

