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

// 2018.8.4 

// leetcode 671 : findSecondMinimumValue 


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution 1: recursion
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int val = -1, left = -1, right = -1;
        if (root->left && root->right) {
            if (root->left->val > root->val) left = root->left->val;
            else left = findSecondMinimumValue(root->left);
            if (root->right->val > root->val) right = root->right->val;
            else right = findSecondMinimumValue(root->right);
        }
        if (left == -1) val = right;
        else if (right == -1) val = left;
        else val = min(left, right);
        return val;
    }
};



int main()
{



    return 0;
}

