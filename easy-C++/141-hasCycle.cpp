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

// 2018.7.17

// leetcode 141 : Linked List Cycle 


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// solution 1 : typical two pointers , one quick and one slow
// time: O(n+k)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode * fast = head->next, * slow = head;
        while (fast != nullptr && slow != nullptr) {
            if (fast == slow) return true;
            if (fast->next != nullptr) fast = fast->next->next;
            else return false;
            slow = slow->next;
        }
        return false;
    }
};

// solution 2 : uae hash map (set/map),  one pointer to traverse, save address to map untill nullptr, if reapeat, return false

class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        set<ListNode *> S;
        ListNode * p = head;
        while (p != nullptr) {
            if (S.find(p) == S.end()) {
                S.insert(p);
                p = p->next;
            }
            else return true;
        }
        return false;
    }
};

 

int main()
{



    return 0;
}

