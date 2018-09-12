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

// leetcode 19 : removeNthFromEnd 

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// solution 1 : two pointers
// notice : list without a head node
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * p = head, * pk = head;
        int count = 0;
        while (p) {
            if (count <= n) count ++;
            else pk = pk->next;
            p = p->next;
        }
        ListNode * tmp;
        if (count == n) {
            tmp = head->next;
            delete head;
            return tmp;
        }
        else {
            tmp = pk->next;
            pk->next = tmp->next;
            return head;
        }
    }
};


// solution 2 : do not free the memory
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * p = head, * pk = head, * tmp;
        for (int i = 0; i < n; i ++) {
            p = p->next;
        }
        if (p == NULL) return head->next;
        while (p->next) {
            p = p->next;
            pk = pk->next;
        }
        pk->next = pk->next->next;
        return head;
    }
};


int main()
{
    ListNode * head = new ListNode (0);
    head->next = new ListNode (1);
    Solution2 S;
    
    ListNode * p = S.removeNthFromEnd(head, 1);
    cout << p->val << endl;


    return 0;
}

