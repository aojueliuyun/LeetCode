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

// 2018.7.22

// leetcode 234 : isPalindrome / 判断一个链表是否是回文链表

// requier : O(n) time & O(1) space




//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(nullptr) {}
}; 

// solution : save values to a vector, and judge ------------> memory limit exceed.
// time: O(n)
// space: O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while (head) {
        	vals.push_back(head->val);
		}
		for (auto left=vals.begin(), right=vals.end()-1; left < right; left ++, right --) {
			if (*left != *right) return false;
		}
		return true;
    }
};


// soolution 2 : reverse the second half list ans compare with first half list.
// time : O(n)
// space : O(1)
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode * slow = head, * fast = head;
        while (fast && fast->next) {
        	slow = slow->next;
        	fast = fast->next->next;
		}
		ListNode * temp; 
		if (fast) temp = slow->next;  // the number of nodes is even / 偶数 
		else temp = slow;             // the number of node is odd / 奇数 
		slow = nullptr;
		while (temp) {                // reverse the sublist (temp to end)
			ListNode * tp = slow;
			slow = temp;
			temp = temp->next;
			slow->next = tp;
		}
		while (head && slow) {
			if (head->val != slow->val) return false;
			head = head->next;
			slow = slow->next;
		}
		return true;
    }
};



int main()
{



	return 0;
}

