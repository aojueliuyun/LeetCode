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

// leetcode 232 : implement a stack by using queues / 用栈实现队列


// solution 1 : move element to the bottom of a stack when pushing through another stack
class MyQueue {
private:
	stack<int> s1, s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!s1.empty()) {
        	s2.push(s1.top());
        	s1.pop();
		}
		s1.push(x);
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
    	int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */


int main()
{



	return 0;
}

