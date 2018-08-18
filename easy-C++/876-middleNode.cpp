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

// leetcode 876 : middleNode / 链表的中间结点


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// solution 1 : tow pointers --> fast and slow 
// time : O(n)
// space: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow = head, * fast = head;
        while (fast) {
        	if (fast->next == nullptr) break;
        	slow = slow->next;
        	fast = fast->next;
        	if (fast->next) fast = fast->next;
		}
		return slow;
    }
};


// solution 2 : input to an array
// time & sapce : O(N)
class Solution2 {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode *> A = {head};
        while (A.back()->next)
        	A.push_back(A.back()->next);
        return A[A.size()/2];
    }
};


// solution 3 : same as solution 1 
// time: O(n)
// space : O(1)
class Solution3 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow = head, * fast = head;
        while (fast && fast->next) {
        	slow = slow->next;
        	fast = fast->next->next;
		}
		return slow;
    }
};



int main()
{
	ListNode * head = new ListNode(0), *p = head;
	for (int i = 1; i <= 5; i ++) {
		p->next = new ListNode(i);
		p = p->next;
	}
	p = head->next;
	while (p) {
		cout << p->val << "->";
		p = p->next;
	}
	
	Solution3 S;
	ListNode * mid = S.middleNode(head);
	cout << mid->val << endl;
	while (mid) {
		cout << mid->val << "->";
		mid = mid->next;
	}

	return 0;
}

