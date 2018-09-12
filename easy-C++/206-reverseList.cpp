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
#include<unordered_map>
using namespace std;

// 2018.7.22

// leetocde 206 : reverse linked List 
// require : use iteration and recursion


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 
 
// solution 1 : use iteration , insert old node to the new list's head 
// time: O(n)
// space: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode Head(0);
        while (head) {
            ListNode * tmp = Head.next;
            Head.next = head;
            head = head->next;
            Head.next->next = tmp;
        }
        return Head.next;
    }
}; 


// solution : use recursion  ------> get tail : head and tail as arguments
// time : O(n)
// space: O(1)
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode * tail = head;
        while (tail->next) tail = tail->next;
        Reverse(head, tail);
        return haed;
    }
    void Reverse(ListNode* & head, ListNode* & tail) { // recursion
        if (head == nullptr || head == tail) return;
        ListNode * phead = head->next, * ptail = tail;
        Reverse(phead, ptail);
        head->next = nullptr;
        ptail->next = head;
        head = phead;
        tail = ptail->next;
    }
}; 


int main()
{



    return 0;
}

