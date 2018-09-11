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

// leetcode 421 : findMaximumXOR


// solution -1 : brute-force, no doubt will get a TLE 
// time : O(n^2)
class Solution_1 {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i+1; j < nums.size(); j ++) {
                res = max(nums[i]^nums[j], res);
            }
        }
        return res;
    }
};


// solution 1 : use trie tree
// time : O(32n)
// execution time : 68 ms 
class Solution {
private:
    struct TreeNode {
        TreeNode * childs[2];
        TreeNode() {
            fill(childs, childs + 2, nullptr);
        }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        TreeNode * root = new TreeNode();
        for (auto x : nums) {  // build the trie tree, from high bit to low bit
            TreeNode * cur = root;
            for (int j = 31; j >= 0; j --) {
                int index = (x & (1 << j)) ? 1 : 0;  // get the i-th bit of x
                if (!cur->childs[index]) {
                    cur->childs[index] = new TreeNode;
                }
                cur = cur->childs[index]; 
            }
        }
        int res = 0;  // find the max xor value for every value
        for (auto x : nums) {
            TreeNode * cur = root;
            int tmpres = 0;
            for (int j = 31; j >= 0; j --) {
                int index = (x & (1 << j)) ? 0 : 1;  // the opposite index of i-th bit
                if (cur->childs[index]) {
                    tmpres += 1 << j;
                }
                else index = 1 - index;
                cur = cur->childs[index];
            }
            res = max(res, tmpres); 
        }
        return res;
    }
};


// solution 2 : the optimazition of solution 1, search when inserting
// time : O(32n)
// execution time : 36 ms
class Solution2 {
private:
    struct TreeNode {
        TreeNode * childs[2];
        TreeNode() {
            fill(childs, childs + 2, nullptr);
        }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        TreeNode * root = new TreeNode();
        int res = 0;
        for (auto x : nums) {
            TreeNode * cur = root, * opp = root;
            int tmpres = 0;
            for (int j = 31; j >= 0; j --) {
                int index = (x & (1 << j)) ? 1 : 0;
                int another = 1 - index;
                if (!cur->childs[index]) {
                    cur->childs[index] = new TreeNode;
                }
                cur = cur->childs[index];
                if (opp->childs[another]) {
                    tmpres += (1 << j);
                }
                else another = 1 - another;
                opp = opp->childs[another];
            }
            res = max(res, tmpres);
        }
        return res;
    }
};



int main()
{



    return 0;
}

