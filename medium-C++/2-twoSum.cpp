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
#include<bitset>
#include<unordered_map>
using namespace std;

// 2018.7.27

// leetcode 2 : two Sum



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// solution : just simulation
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0), * p = & head;
        int sum = 0, carry = 0;
        while (l1 || l2) {
            sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            ListNode * temp = new ListNode(sum % 10);
            p->next = temp;
            p = p->next;
        }
        if (carry != 0) {
            ListNode * temp = new ListNode(carry);
            p->next = temp;
        }
        return head.next;
    }
};


int main()
{


    return 0;
}

