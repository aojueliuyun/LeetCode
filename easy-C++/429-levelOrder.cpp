#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
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

// 2018.7.26

// leetcode 429 : levelOrder / 层序遍历



// Definition for a tree Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// solution : just use queue to BFS
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<pair<Node *, int>> Q;
        vector<vector<int>> res;
        Q.push({root, 1});
        vector<int> vec;
        int level = 1;
        while (!Q.empty()) {
        	pair<Node *, int> cur = Q.front();
        	Q.pop();
        	if (cur.first == nullptr)
        		continue;
        	for (auto node : cur.first->children) {
        		Q.push({node, cur.second + 1});
			}
			if (cur.second == level) {
				vec.push_back(cur.first->val);
			}
			else {
				res.push_back(vec);
				vec.clear();
				vec.push_back(cur.first->val);
				level ++;
			}
		}
		if (root != nullptr)
			res.push_back(vec);
		return res;
    }
};


// solution 2 : do not save the information of level to queue
class Solution2 {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> Q;
        vector<vector<int>> ans;
        if (root == nullptr)
        	return ans;
        Q.push(root);
        while (!Q.empty()) {
        	vector<int> seq;
        	int n = Q.size();
        	for (int i = 0; i < n; i ++) {
        		Node * cur = Q.front();
        		Q.pop();
        		for (auto node : cur->children) {
        			Q.push(node);
				}
				seq.push_back(cur->val);
			}
			ans.push_back(seq);
		}
		return ans;
    }
};




int main()
{



	return 0;
}

