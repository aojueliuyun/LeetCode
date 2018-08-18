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

// leetcode 83 : 实现单链表



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// solution :
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == NULL) return head;
        ListNode * pre = head, * now = pre->next;
        while(now != NULL) {
        	if(now->val == pre->val) {
        		pre->next = now->next;
        		delete now;
        		now = pre->next;
			}
			else {
				pre = pre->next;
				now = now->next;
			}
		}
		return head;
    }
};
 
int main()
{



	return 0;
}

