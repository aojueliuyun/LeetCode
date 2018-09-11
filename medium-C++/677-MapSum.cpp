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

// leetcode 677 : MapSum


// solution : use trie tree
struct Node {
    int val;
    bool ending;
    unordered_map<char, Node *> childs;
    Node(int v = 0, bool b = false) : val(v), ending(b) {  }
};

class MapSum {
private:
    Node * root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node * cur = root;
        for (auto c : key) {
            if (!cur->childs.count(c)) {
                cur->childs[c] = new Node();
            }
            cur = cur->childs[c];
        }
        cur->ending = true;
        cur->val = val;
    }
    
    int sum(string prefix) {
        Node * cur = root;
        for (auto c : prefix) {
            if (cur->childs.count(c)) {
                cur = cur->childs[c];
            }
            else return 0;
        }
        return getsum(cur);
    }
    int getsum(Node * root) {
        int res = 0;
        if (root->ending) 
            res += root->val;
        for (auto p : root->childs) {
            res += getsum(p.second);
        }
        return res;
    }
};


// solution 2 : just use map to save values, and use map::lower_bound() to search
class MapSum2 {
private:
    map<string, int> M;
public:
    /** Initialize your data structure here. */
    MapSum2() {
        
    }
    
    void insert(string key, int val) {
        M[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0, n = prefix.size();
        for (auto it = M.lower_bound(prefix); it != M.end(); it ++) {
            if (it->first.substr(0,n) != prefix) break;
            else res += it->second; 
        }
        return res;
    }
}; 


int main()
{



    return 0;
}

