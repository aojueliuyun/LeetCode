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

// leetcode 92 : reverseBetween / ·´×ªÁ´±í II
// require : one round traversal


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// solution 1 : 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 1;
        ListNode * p = head, * pre = nullptr;
        while (count < m) {
            pre = p;
            p = p->next;
            count ++;
        }
        ListNode * r = p->next, * tmp = p;
        while (count < n) {
            if (pre == nullptr) {  // m == 1, reverse from head
                head = r;
                r = r->next;
                head->next = p;
                p = head;
            }
            else {
                pre->next = r;
                r = r->next;
                pre->next->next = p;
                p = pre->next;
            }
            count ++;
        }
        tmp->next = r;  // the tail node of the m-n sublist
        return head;
    }
};
 


int main()
{



    return 0;
}

