#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<unordered_map>
using namespace std;

// 2018.7.15

// leetcode 21 : mergeTwoLists


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Solution 1 :
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * p = new ListNode(0), * merge = p;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p -> next = l1;
                l1 = l1->next;
            }
            else {
                p -> next = l2; 
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) p -> next = l1;
        if (l2) p -> next = l2;
        ListNode * res = merge->next;
        delete merge;
        return res;
    }
};


int main()
{
    


    return 0;
}

