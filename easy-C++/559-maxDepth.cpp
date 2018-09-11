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

// leetcode 559 : maxDepth / n叉树的最大深度 BFS



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

// solution : recursion : just BFS
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        else if (root->children.empty())
            return 1;
        else {
            int maxlevel = 0;
            for (auto node : root->children) {
                int depth = maxDepth(node);
                if (depth > maxlevel)
                    maxlevel = depth;
            }
            return maxlevel + 1;
        }
    }
};





int main()
{



    return 0;
}

