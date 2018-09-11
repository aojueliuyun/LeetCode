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

// leetcode 648 : replaceWords


// solution : use unordered_set to save
// execution time : 156 ms
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string cur, res;
        unordered_set<string> S(dict.begin(), dict.end());
        for (auto c : sentence) {
            if (c == ' ') {
                res += shortestPrefix(S, cur);
                res += ' ';
                cur.clear();
            }
            else cur += c;
        }
        if (!cur.empty()) res += shortestPrefix(S, cur);
        return res;
    }
    string shortestPrefix(unordered_set<string> & S, string sentence) {
        for (int i = 1; i < sentence.length(); i ++) {
            if (S.count(sentence.substr(0, i))) {
                return sentence.substr(0, i);
            }
        }
        return sentence;
    }
};

// solutoin 2 : use sstream to input
// execution time : 144 ms
class Solution2 {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string res;
        istringstream iss(sentence);
        string word;
        unordered_set<string> S(dict.begin(), dict.end());
        while (iss >> word) {
            bool flag = false;
            for (int i = 1; i < word.length(); i ++) {
                if (S.count(word.substr(0, i))) {
                    res += word.substr(0, i);
                    res += " "; 
                    flag = true;
                    break;
                }
            }
            if (!flag)  res += word + " ";
        }
        res.pop_back();
        return res;
    }
};


// solution 3 : use trie tree
// execution time : 60 ms
struct Node {
    bool ending;
    unordered_map<char, Node *> childs;
    Node(bool b = false) : ending(b) {  } 
};

class Solution3 {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Node * root = new Node();
        for (auto str : dict) {
            insertWord(root, str);
        }
        istringstream iss(sentence);
        string word, res;
        while (iss >> word) {
            res += havePrefix(root, word) + " ";
        }
        res.pop_back();
        return res;
    }
    void insertWord(Node * root, string str) {
        Node * p = root;
        for (auto c : str) {
            if (!p->childs.count(c)) {
                p->childs[c] = new Node();
            }
            p = p->childs[c];
        }
        p->ending = true;
    }
    string havePrefix(Node * root, string sentence) {
        string cur;
        Node * p = root;
        for (auto c : sentence) {
            if (p->childs.count(c)) {
                cur += c;
                p = p->childs[c];
                if (p->ending) return cur;
            }
            else break;
        }
        return sentence;
    }
};

int main()
{



    return 0;
}

