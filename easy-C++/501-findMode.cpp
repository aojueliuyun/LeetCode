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

// leetcode 501 : findMode / 二叉搜索树中的众数



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution 1 : of course recursion, no matter choose what order to traverse
// time: O(n)
// space: O(1)
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        int last = 0, lastNum = 0, maxNum = 1;
        vector<int> res;
        if (root) Find(root, last, lastNum, maxNum, res);
        return res;
    }
    void Find(TreeNode * root, int & last, int & lastNum, int & maxNum, vector<int> & res) {
        if (root) {
            Find(root->left, last, lastNum, maxNum, res);
            if (root->val == last) {
                lastNum ++;
                if (lastNum == maxNum) {
                    res.push_back(last);
                }
                else if (lastNum > maxNum) {
                    maxNum = lastNum;
                    res.clear();
                    res.push_back(last);
                }
            }
            else {
                last = root->val;
                lastNum = 1;
                if (maxNum == 1 || res.empty())
                    res.push_back(last);
            }
            Find(root->right, last, lastNum, maxNum, res);
        }
    }
};


int main()
{
    cout << LLONG_MAX << endl;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode (1);
    root->right = new TreeNode (2);
    Solution S;
    cout << S.findMode(root)[0] << endl;    


    return 0;
}

