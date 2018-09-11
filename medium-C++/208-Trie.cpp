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

// 2018.9.1

// leetcode 208 : Trie || implement a trie tree 

// std::find_if : template< class InputIt, class UnaryPredicate >
//                InputIt find_if( InputIt first, InputIt last, 
//                                 UnaryPredicate p );


// solution : use vector<Node *> to save childs
// execution time : 72 ms

class Trie {
private:
    struct Node {
        char ch;
        bool ending;
        vector<Node *> childs;
        Node(char _ch = '\0', bool _end = false) : ch(_ch), ending(_end) {}
    };
    inline vector<Node *>::iterator findNode(Node * p, char c) {
        return find_if(p->childs.begin(), p->childs.end(), [c](Node * p) -> bool { return p->ch == c; } );
    }
    Node * root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * p = root;
        for (auto c : word) {
            auto iter = findNode(p, c); // use lambda
            if (iter != p->childs.end()) {
                p = *iter;
            }
            else {
                p->childs.push_back(new Node(c));
                p = p->childs.back();
            }
        }
        p->ending = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * p = root;
        for (auto c : word) {
            auto iter = findNode(p, c);
            if (iter != p->childs.end()) {
                p = *iter;
            }
            else return false;
        }
        return p->ending;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * p = root;
        for (auto c : prefix) {
            auto iter = findNode(p, c);
            if (iter != p->childs.end()) {
                p = *iter;
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */



// solution 2 : use hash table to save childs  || hash map also a good choice like map<char, Node *>, then you can use std::map::find() 
// execution time : 104 ms

class Trie2 {
private:
    struct Node {
        bool ending;
        vector<Node *> childs;
        Node(bool _end = false) : ending(_end) {
            childs = vector<Node *>(26, nullptr);
        }
    };
    Node * root;
public:
    /** Initialize your data structure here. */
    Trie2() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * p = root;
        for (auto c : word) {
            if (p->childs[c-'a'] == nullptr) {
                p->childs[c-'a'] = new Node();
            }
            p = p->childs[c-'a'];
        }
        p->ending = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * p = root;
        for (auto c : word) {
            if (p->childs[c-'a']) {
                p = p->childs[c-'a'];
            }
            else return false;
        }
        return p->ending;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * p = root;
        for (auto c : prefix) {
            if (p->childs[c-'a']) {
                p = p->childs[c-'a'];
            }
            else return false;
        }
        return true;
    }
};



int main()
{



    return 0;
}

