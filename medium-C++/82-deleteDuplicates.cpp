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

// leetcode 82 : deleteDuplicates / 删除排序链表中的重复元素 II


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// solution 1 : use hash map to save all values
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == nullptr || head->next == nullptr) return head;  // zero or one node
        ListNode Head(0), * p = & Head;
        Head.next = head;
        unordered_map<int, int> record; 
        while (p->next) {
        	record[p->next->val] ++;
        	p = p->next;
		}
		p = & Head;
		while (p->next) {
			if (record[p->next->val] > 1) {
				p->next = p->next->next;     // did not free the memory
			}
			else p = p->next;
		}
		return Head.next;
    }
};


// solution 2 : ORZ !!  Can not I write code like this ?
class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == nullptr) return head;
    	ListNode * pre = nullptr, * cur = head;
    	while (cur) {
    		if (cur->next && cur->next->val == cur->val) {
    			int a = cur->val;
    			while (cur->next && cur->next->val == a) {
    				cur = cur->next;
				}
				if (pre == nullptr) head = cur->next;
				else pre->next = cur->next;
			}
			else pre = cur;
			cur = cur->next;
		}
		return head;
    }
};


// solution 3 : use a fake head node !
class Solution3 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode * fakeNode = new ListNode (0);
    	fakeNode->next = head;
    	ListNode * pre = fakeNode;
    	while (head) {
    		if (head->next && head->next->val == head->val) {
    			int v = head->val;
    			while (head && head->val == v) {
    				pre->next = head->next;
    				delete head;
    				head = pre->next;
				}
			}
			else {
				pre = head;
				head = head->next;
			}
		}
		return fakeNode->next;
    }
};


int main()
{



	return 0;
}

