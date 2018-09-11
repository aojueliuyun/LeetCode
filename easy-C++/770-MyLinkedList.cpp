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

// 2018.8.10

// leetcode 770 : MyLinkedList / 设计链表（单链表或者双链表）


// solution 1 : single linked list
// execution time : 108 ms
typedef struct Node {
    int val;
    Node * next;
    Node(int x, Node *p = nullptr) : val(x), next(p) {}
} * pNode;

// attention : index start from 0
class MyLinkedList {
private:
    Node * head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new Node(0);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node * p = head;
        for (int i = 0; i <= index && p; i ++) {
            p = p->next;
        }
        return p ? p->val : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        head->next = new Node(val, head->next);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node * p = head;
        while (p->next) p = p->next;
        p->next = new Node(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node * p = head;
        int i;
        for (i = 0; i < index && p->next; i ++) {
            p = p->next;
        }
        if (p->next || i == index) {
            p->next = new Node(val, p->next);
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node * p = head;
        for (int i = 0; i < index && p->next; i ++) {
            p = p->next;
        }
        if (p->next) {
            Node * tmp = p->next;
            p->next = tmp->next;
            delete tmp;
        }
    }
};





int main()
{
    MyLinkedList L;
    cout << L.get(0) << endl;
    L.addAtIndex(1,2);
    cout << L.get(0) << endl;
    cout << L.get(1) << endl;
    L.addAtIndex(0,1);
    cout << L.get(0) << endl;
    cout << L.get(1) << endl;


    return 0;
}

