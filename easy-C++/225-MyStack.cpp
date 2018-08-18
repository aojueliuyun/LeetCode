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

// leetcode 225 : use queue to implement a stack

// solution 1 : push to q1, recycle elements from q1 and q2 when popping
// pop time: O(e)  e is number of elements of current queue
// push tiem: O(1)
// get top time: O(1)
class MyStack {
private:
	queue<int> q1,q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
    	
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
    	int element;
        if (q1.empty()) {
        	element = q2.back();
        	while (q2.size() > 1) {
        		q1.push(q2.front());
        		q2.pop();
			}
			element = q2.front();
			q2.pop();
		}
		else {
			while (q1.size() > 1) {
				q2.push(q1.front());
				q1.pop();
			}
			element = q1.front();
			q1.pop();
		}
		return element;
    }
    
    /** Get the top element. */
    int top() {
        if (q1.empty()) return q2.back();
        else return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};




// solution 2 : make q a stack through b. when pushing, remove all elements. put new element on q's front, remove others back.
// push time: O(e)  e is the number of current elements of stack
// pop time: O(1)
// get top time : O(1)
class MyStack2 {
private:
	queue<int> q, b;
public:
    /** Initialize your data structure here. */
    MyStack2() {
    	
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while (!q.empty()) {
        	b.push(q.front());
        	q.pop();
		}
		q.push(x);
		while (!b.empty()) {
			q.push(b.front());
			b.pop();
		}
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
    	int tmp = q.front();
    	q.pop();
    	return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};


int main()
{
	

	return 0;
}
