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

// leetcode 538 : convertBST / 反转二叉树


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// solution 1 : traverse & recursion 
// execution time : 1428 ms --------> What's wroung ?
//                  40 ms in the second time ?  en ~~~
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convert(root, sum);
        return root;
    }
    void convert(TreeNode * root, int & sum) {
    	if (root) {
    		convert(root->right, sum);
			root->val += sum;
    		sum = root->val;
    		convert(root->left, sum);
		}
	}
};


int main()
{



	return 0;
}

