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

// leetcode 211 : WordDictionary


// solution : use hash map to save childs
class WordDictionary {
private:
    struct TreeNode {
        bool ending;
        unordered_map<char, TreeNode *> childs;
        TreeNode(bool b = false) : ending(b) {  }
    };
    TreeNode * root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TreeNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TreeNode * p = root;
        for (auto c : word) {
            if (!p->childs.count(c)) {
                p->childs[c] = new TreeNode();
            }
            p = p->childs[c];
        }
        p->ending = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchTree(root, word);
    }
    
    bool searchTree(TreeNode * p, string word) {
        if (word.length() == 1) { // the export of recursion
            if (word[0] == '.') {
                for (auto tmp : p->childs) {
                    if (tmp.second->ending) return true;
                }
                return false;
            }
            else {
                if (p->childs.count(word[0]) && p->childs[word[0]]->ending) return true;
                else return false;
            }
        }
        for (int i = 0; i < word.length(); i ++) {
            if (word[i] == '.') {
                for (auto tmp : p->childs) {  
                    if (searchTree(tmp.second, word.substr(i+1))) {
                        return true;
                    }
                }
                return false;
            }
            else {
                if (p->childs.count(word[i])) {
                    return searchTree(p->childs[word[i]], word.substr(i+1));
                }
                else return false;
            }
        }
    }
};


// solution 2 : use array to save childs
class WordDictionary2 {
private:
    struct TreeNode {
        bool ending;
        TreeNode * childs[26]   ;
        TreeNode(bool b = false) : ending(b) {
            fill(childs, childs+26, nullptr);  // use std::fill in <algorithm> to reaplace memset
        }
    };
    TreeNode * root;
public:
    /** Initialize your data structure here. */
    WordDictionary2() {
        root = new TreeNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TreeNode * p = root;
        for (auto c : word) {
            if (!p->childs[c-'a']) {
                p->childs[c-'a'] = new TreeNode();
            }
            p = p->childs[c-'a'];
        }
        p->ending = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchTree(root, word, 0);
    }
    
    bool searchTree(TreeNode * p, string word, int i) {
        if (i == word.size()) return p->ending;
        if (word[i] == '.') {
            for (auto tmp : p->childs) {  // C array also can use range for loop, first know, much to learn
                if (tmp && searchTree(tmp, word, i + 1)) return true;
            }
            return false;
        }
        else {
            return p->childs[word[i]-'a'] && searchTree(p->childs[word[i]-'a'], word, i + 1);
        }
    }
};


int main()
{


    return 0;
}

