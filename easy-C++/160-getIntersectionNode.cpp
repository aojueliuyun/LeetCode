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

// leetcode 160 : getIntersectionNode
// list Node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// solution : use hash map / set, traverse
// wrost: O(m + n)
// best time: O(m) m ,n is length of list A, B
// space: O(m)
// run time: 44ms
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> SA;
        while (headA != nullptr) {
            SA.insert(headA);
            headA = headA->next;
        }
        while (headB != nullptr) {
            if (SA.find(headB) != SA.end()) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

// solution 2 : get length of list A & B, move A & B's pointer forward from appropriate location meantime. 
// time: O(m+n)
// space: O(1)
// run time: 28ms
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        if (lenA > lenB)
            for (int i = 0; i < lenA-lenB; i++) headA = headA -> next;
        else for (int i = 0; i < lenB-lenA; i++) headB = headB -> next;
        while (headA && headB) {
            if (headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return nullptr;
    }
    int getLength(ListNode * p) {
        int count = 0;
        while (p != nullptr) {
            p = p->next;
            count ++;
        }
        return count;
    }
};



int main()
{



    return 0;
}

