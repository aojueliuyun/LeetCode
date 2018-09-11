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

// leetcode 108 : sortedArrayToBST 排序数组转换为平衡二叉树 


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution 1 : recursive 
class Solution {
public:
    TreeNode * sortedArrayToBST(vector<int>& nums) {
        return arrayToBST(nums, 0, nums.size()-1);
    }
    TreeNode * arrayToBST(vector<int> & nums, int l, int r) {
        if (l > r) return nullptr;
        TreeNode * root, * left, * right;
//        if (l == r) return new TreeNode(nums[l]);
//        if (l-r == 1) {
//            root = new TreeNode(nums[r]);
//            left = new TreeNode(nums[l]);
//            root -> left = left;
//            return root;
//        }
        // 上面两个if语句完全可以省略 
        int mid = (l + r) / 2;
        root = new TreeNode(nums[mid]);
        root -> left = arrayToBST(nums, l, mid-1);
        root -> right = arrayToBST(nums, mid+1, r);
        return root; 
    }
}; 


int main()
{



    return 0;
}

