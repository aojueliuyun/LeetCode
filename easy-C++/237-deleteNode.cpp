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

// 2018.7.23

// leetcode 237 : deleteNode / 删除链表中的给定节点 


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// solution : swap node and node->next, and delete node->next
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr) {
            delete node;
            return;
        }
        else {
            swap(node->val, node->next->val);
            ListNode * temp = node->next;
            node->next = temp->next;
            delete temp;
        }
    }
};

// solution 2 : do not need to free memory
class Solution2 {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};


int main()
{



    return 0;
}

