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

// 2018.9.2

// leetcode 25 : reverseKGroup

// requeire : swap nodes and O(1) extra space ---------> solution 3


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// solution : save to vector and reconstruct a list
// time : O(n)
// space: O(n)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode *> Nodes;
        while (head) {
            Nodes.push_back(head);
            head = head->next;
            Nodes.back()->next = nullptr;  // set null in case a loop
        }
        for (int i = 0; i < Nodes.size(); i += k) {
            if (i+k <= Nodes.size()) {
                reverse(Nodes.begin() + i, Nodes.begin() + i + k);
            }
        }
        ListNode newHead(0), * p = & newHead;
        for (auto node : Nodes) {
            p->next = node;
            p = p->next;
        }
        return newHead.next;
    }
};


// solution 2 : swap values
// time : O(n)
// space: O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode newHead(0), * p = & newHead;
        p->next = head;
    }
};


int main()
{



    return 0;
}

