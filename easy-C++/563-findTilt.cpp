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

// leetcode 563 : findTilt / ÇóÊ÷µÄÆÂ¶È



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// solution 1 : just recursion || get the sum of node's tilt when get summation of nodes
class Solution {
public:
    int findTilt(TreeNode* root) {
        int tiltSum = 0;
        getTilt(root, tiltSum);
        return tiltSum;
    }
    int getTilt(TreeNode * root, int & tiltSum) { // return to the sum of the tree nodes values
		if (root == nullptr) return 0;
		int suml = getTilt(root->left, tiltSum);
		int sumr = getTilt(root->right, tiltSum);
		tiltSum += abs(suml - sumr);
		return root->val + suml + sumr; 
	}
}; 


// solution 2 : same sa solution 1, just different writing  || recursion is so interesting !!!
class Solution2 {
public:
    int findTilt(TreeNode* root) {
    	int sum;
        return getTilt(root, sum);
    }
    int getTilt(TreeNode * root, int & sum) { // return to the sum of the tree nodes tilts
    	if (root == nullptr) return 0;
		int suml = 0, sumr = 0;
		int tiltSum = getTilt(root->left, suml) + getTilt(root->right, sumr);
		sum = root->val + suml + sumr;
		return tiltSum + abs(suml - sumr);
	}
};



int main()
{



	return 0;
}

