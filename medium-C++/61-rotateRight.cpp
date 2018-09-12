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

// leetcode 61 : rotateRight


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// solution 1 : get the length of the list and rotate
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode * p = head;
        while (p) {
            p = p->next;
            len ++;
        }
        if (len == 0) return head;
        k = k % len;
        if (k == 0) return head;
        ListNode * mid = head, *r, * res;
        for (int i = 0; i < len-k-1; i ++) {
            mid = mid->next;
        }
        r = mid;
        for (int i = 0; i < k; i ++) {
            r = r->next;
        }
        res = mid->next;
        mid->next = nullptr;
        r->next = head;
        return res;
    }
};

 
void disp(ListNode * L) {
    while (L) {
        cout << L->val << "->";
        L = L->next;
    }
    cout << endl;
}

int main()
{
    ListNode * L = new ListNode(1), * p = L;
    for (int i = 2; i <= 5; i ++) {
        p->next = new ListNode (i);
        p = p->next;
    }
    disp(L);
    
    Solution S;
    L = S.rotateRight(L, 12);
    disp(L);


    return 0;
}

