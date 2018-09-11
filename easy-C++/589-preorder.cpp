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

// leetcode 589 : preorder / Ç°Ðò±éÀún²æÊ÷


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

// solution 1 : use recursion || so easy
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preTraverse(root, res);
        return res;
    }
    void preTraverse(Node * root, vector<int> & vec) {
        if (root) {
            vec.push_back(root->val);
            for (auto node : root->children) {
                preTraverse(node, vec);
            }
        }
    }
}; 


// solution 2 : use iteration || use std::stack to simulation
class Solution2 {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node *> data;
        data.push(root);
        while (!data.empty()) {
            Node * tmp = data.top();
            data.pop();
            if (tmp) {
                res.push_back(tmp->val);
                for (int i = tmp->children.size()-1; i >= 0; i --) {
                    data.push(tmp->children[i]);
                }
            }
        }
        return res;
    }
};


int main()
{



    return 0;
}

