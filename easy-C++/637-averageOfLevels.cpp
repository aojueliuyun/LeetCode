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

// leetcode 673 : averageOfLevels 


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution 1 : recursion
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<long long, int>> vec;
        getAverage(root, vec, 1);
        vector<double> res;
        for (auto x : vec) {
            res.push_back(x.first*1.0 / x.second);
        }
        return res;
    }
    void getAverage(TreeNode * root, vector<pair<long long, int>> & vec, int level) {
        if (root == nullptr) return;
        if (vec.size() < level) {
            vec.push_back({root->val, 1});
        }
        else {
            vec[level-1].first += root->val;
            vec[level-1].second ++;
        }
        getAverage(root->left, vec, level+1);
        getAverage(root->right, vec, level+1);
    }
};


// solution 2 : use queue
class Solution2 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        long long sum = 0, n = 0;
        queue<TreeNode *> Q;
        vector<double> res;
        Q.push(root);
        while (!Q.empty()) {
            n = Q.size();
            sum = 0;
            for (int i = 0; i < n; i ++) {
                TreeNode * tmp = Q.front();
                Q.pop();
                sum += tmp->val;
                if (tmp->left)
                    Q.push(tmp->left);
                if (tmp->right)
                    Q.push(tmp->right);
            }
            res.push_back(double(sum)/n);
        }
        return res;
    }
};


int main()
{



    return 0;
}

