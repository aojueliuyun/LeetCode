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

// 2018.7.21

// leetcode 203 : Remove Linked List Elements 删除链表中的节点



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

// solution
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode Head(0);
    	Head.next = head;
    	ListNode * p = & Head;
    	while (p && p->next) {
    		if (p->next->val == val) {
    			ListNode * temp = p->next;
    			p->next = temp->next;
    			delete temp;
			}
			else p = p->next;
		}
		return Head.next;
    }
};


int main()
{



	return 0;
}

