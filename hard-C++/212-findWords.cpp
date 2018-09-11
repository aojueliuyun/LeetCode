#include<iostream>
#include<fstream>
#include<sstream>
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

// 2018.9.9

// leetcode 212 : findWords ------------> What a good problem !!! 


// solution : DFS + trie tree
class Solution {
private:
    struct TreeNode {
        bool ending;  // isWord / end with
        unordered_map<char, TreeNode *> childs;
        TreeNode(bool b = false) : ending(b) {  }
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TreeNode * root = CreateTrie(words);
        int r = board.size(), c = board[0].size();
        vector<string> res;
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                if (root->childs.count(board[i][j])) {
                    DFS(board, root->childs[board[i][j]], i, j, "", res);
                }
            }
        }
        return res;
    }
    
    TreeNode * CreateTrie(vector<string> & words) {
        TreeNode * root = new TreeNode();
        for (auto str : words) {
            TreeNode * cur = root;
            for (auto c : str) {
                if (!cur->childs.count(c)) {
                    cur->childs[c] = new TreeNode();
                }
                cur = cur->childs[c];
            }
            cur->ending = true;
        }
        return root;
    }
    
    // DFS, set '#' denote visited, change back when finished
    void DFS(vector<vector<char>> & board, TreeNode * root, int x, int y, string cur, vector<string> & res) {
        int r = board.size(), c = board[0].size();
        cur += board[x][y];
        if (root->ending) {
            res.push_back(cur);
            root->ending = false;
        }
        char ch = board[x][y];
        board[x][y] = '#';
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i ++) {
            int cx = x + dir[i][0];
            int cy = y + dir[i][1];
            if (cx >= 0 && cx < r && cy >= 0 && cy < c && root->childs.count(board[cx][cy])) {
                DFS(board, root->childs[board[cx][cy]], cx, cy, cur, res);
            }
        }
        board[x][y] = ch;  // change back
    }
};


int main()
{



    return 0;
}

