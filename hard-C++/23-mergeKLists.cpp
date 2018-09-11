#include<iostream>
#include<fstream>
#include<sstream>
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

// 2018.9.2

// leetcode 23 : mergeKLists


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// solution : find min and insert
// time : O(k*n)
// space: O(1)
// execution time : 452 ms
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * res = new ListNode(0), * p = res;
        bool flag = true;
        while (flag) {
            flag = false;
            int now = -1;
            for (int i = 0; i < lists.size(); i ++) {
                if (lists[i]) {
                    if (now == -1 || lists[now]->val > lists[i]->val) {
                        now = i;
                        flag = true;
                    }
                }
            }
            if (flag) {
                p->next = lists[now];
                lists[now] = lists[now]->next;
                p = p->next;
            }
        }
        p = res->next;
        delete res;
        return p;
    }
};  


// solution 2 : save all value in an array, sort and construct list, remember to release memory
// time : O(nlogn) for sort
// space: O(n)
// execution time : 24 ms
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;
        for (auto node : lists) {
            while (node) {
                vals.push_back(node->val);
                ListNode * tmp = node->next;
                delete node;
                node = tmp;
            }
        }
        sort(vals.begin(), vals.end());
        ListNode * res = new ListNode(0), * p = res;
        for (auto x : vals) {
            p->next = new ListNode(x);
            p = p->next;
        }
        p = res->next;
        delete res;
        return p;
    }
};


// solution 3 : like solution 2, save nodes and use these nodes to construct list
// time : O(nlogn)
// space: O(n)
// execution time : 32 ms
class Solution3 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> Nodes;
        for (auto node : lists) {
            while (node) {
                Nodes.push_back(node);
                node = node->next;
            }
        }
        sort(Nodes.begin(), Nodes.end(), [](ListNode * n1, ListNode * n2) -> bool { return n1->val < n2->val; });
        ListNode head(0), * p = & head;
        for (auto node : Nodes) {
            node->next = nullptr;    // necessary, in case a loop 
            p->next = node;
            p = p->next;
        }
        return head.next;
    }
};  



// std::priority_queue  in <queue>
// template<
//     class T,
//     class Container = std::vector<T>,
//     class Compare = std::less<typename Container::value_type>
// > class priority_queue;



// solution 4 : best choice --------> use priority queue || std::priority_queue<>
// time : O(nlogk), n for traversal, logk for the operation of heap
// space : O(n)
// execution time : 40 ms


// function object, for contruting a min heap
struct cmp {
    bool operator() (ListNode * a, ListNode * b) {
        return a->val > b->val;
    }
};

class Solution4 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<ListNode *>, cmp> Q;
        ListNode head(0), * p = & head;
        for (auto node : lists) {
            if (node) Q.push(node);
        }
        while (!Q.empty()) {
            ListNode * tmp = Q.top();
            Q.pop();
            if (tmp->next) {
                Q.push(tmp->next);
            }
            p->next = tmp;
            p = p->next;
        }
        return head.next;
    }
};


// solution 5 : like solution 4, and 4 is better
// time : O(nlogn)
// execution time : 44 ms
class Solution5 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<ListNode *>, cmp> Q;
        ListNode head(0), * p = & head;
        for (auto node : lists) {
            while (node) {
                Q.push(node);
                node = node->next;
            }
        }
        while (!Q.empty()) {
            ListNode * tmp = Q.top();
            Q.pop();
            tmp->next = nullptr;    // necessary in this solution and solution 3.
            p->next = tmp;
            p = p->next;
        }
        return head.next;
    }
};



// for test

vector<ListNode *> get(vector<vector<int>> vals) {
    vector<ListNode *> res;
    for (auto vec : vals) {
        ListNode head(0), * tmp = & head;
        for (auto x : vec) {
            tmp->next = new ListNode(x);
            tmp = tmp->next;
        }
        res.push_back(head.next);
    }
    return res;
}


int main()
{
    vector<vector<int>> test1{{-1, -1, -1}, {-2, -2, -1}};
    vector<ListNode *> lists = get(test1);
    Solution5 S;
    auto res = S.mergeKLists(lists);
    while (res) {
        cout << res->val << " -> ";
        res = res->next;
    }
    cout << endl;

    return 0;
}

