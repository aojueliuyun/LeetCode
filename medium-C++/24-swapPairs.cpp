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

// leetcode 28 : swapPairs of a linked list


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// solution : save nodes to a vector, swap and construct to a list
// time : O(n)
// space: O(n)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        vector<ListNode *> Nodes;
        while (head) {
            Nodes.push_back(head);
            head = head->next;
        }
        for (int i = 1; i < Nodes.size(); i += 2) {
            swap(Nodes[i], Nodes[i-1]);
        }
        ListNode newHead(0), * p = & newHead; 
        for (auto node : Nodes) {
            node->next = nullptr;  // In case the tail of the list become a loop.
            p->next = node;
            p = p->next;
        }
        return newHead.next;
    }
};


// solution 2 : swap values of adjacent nodes
// time : O(n)
// space: O(1)
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * p = head;
        while(p && p->next) {
            swap(p->val, p->next->val);
            p = p->next->next;
        }
        return head;
    }
};


// solution 3 : just swap nodes
class Solution3 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode tmpHead(0), * p = & tmpHead; 
        p->next = head;
        while (p->next && p->next->next) {
            ListNode * tmp = p->next;
            p->next = tmp->next;
            tmp->next = tmp->next->next;
            p->next->next = tmp;
            p = tmp;
        }
        return tmpHead.next;
    }
};



int main()
{



    return 0;
}

