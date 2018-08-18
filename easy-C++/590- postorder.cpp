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

// leetcode 590 :  postorder / 后序遍历二叉树


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


// solution 1 : use recursion
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postTraverse(root, res);
		return res; 
    }
    void postTraverse(Node * root, vector<int> & vec) {
    	if (root) {
    		for (auto node : root->children)
    			postTraverse(node, vec);
    		vec.push_back(root->val);
		}
	}
};

// solution 2 : use iteration , also use std::stack
class Solution2 {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
    	stack<Node *> data;
    	data.push(root);
        while (!data.empty()) {
        	Node * tmp = data.top();
        	data.pop();
        	if (tmp) {
        		for (int i = 0; i < tmp->children.size(); i ++) {
        			data.push(tmp->children[i]);
				}
				res.push_back(tmp->val);
			}
		}
		reverse(res.begin(), res.end()); // return vector<int>(res.rbegin(), res.rend());
		return res;
    }
};



int main()
{



	return 0;
}

