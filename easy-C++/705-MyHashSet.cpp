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

// 2018.8.14

// leetcode 705 : MyHashSet 


// solution 1 : 
struct Node {
    int val;
    Node * next;
    Node(int v = 0, Node * p = nullptr) : val(v), next(p) { }
};

// result : ----------------> TLE !!! --------------> How about just use set
class MyHashSet {
private:
    Node * data;
    int size = 10007;  // hash function : addr = key % size
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data = new Node [size];
    }
    
    void add(int key) {
        int addr = key % size;
        Node * tmp = & data[addr];
        while (tmp->next) {
            if (tmp->next->val < key) {
                tmp = tmp->next;
            }
            else if (tmp->next->val == key) { // exist, do not need insert
                return;
            }
        }
        tmp->next = new Node(key, tmp->next);
    }
    
    void remove(int key) {
        int addr = key % size;
        Node * tmp = & data[addr];
        while (tmp->next) {
            if (tmp->next->val < key) {
                tmp = tmp->next;
            }
            else if (tmp->next->val == key) {
                Node * t = tmp->next;
                tmp->next = t->next;
                delete t;
                break;
            }
            else break; // do not exist
        }
    }
    
    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) {
        int addr = key % size;
        Node * tmp = & data[addr];
        while (tmp->next) {
            if (tmp->next->val < key) {
                tmp = tmp->next;
            }
            else if (tmp->next->val == key) {
                return true;
            }
            else break;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */


// solution 2 : just use vector<bool>
// execution time : 60 ms
class MyHashSet2 {
private:
    vector<bool> data;
public:
    /** Initialize your data structure here. */
    MyHashSet2() {
        data = vector<bool> (1000001, false);
    }
    
    void add(int key) {
        data[key] = true;
    }
    
    void remove(int key) {
        data[key] = false; 
    }
    
    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) {
        return data[key];
    }
};



// solution 3 : use std:set or std::unordered_set
// execution time : 96 ms 
class MyHashSet3 {
private:
    set<int> data;
public:
    /** Initialize your data structure here. */
    MyHashSet3() {
        
    }
    
    void add(int key) {
        data.insert(key);
    }
    
    void remove(int key) {
        data.erase(key);
    }
    
    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) {
        return data.count(key);
    }
};




int main()
{
    MyHashSet3 S;
    S.add(1);
    cout << S.contains(1) << endl;
    S.remove(1);
    cout << S.contains(1) << endl;


    return 0;
}

