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

// 2018.7.17

// leetcode 155 : MinStack

// solution 1 : use vector ----------> Inefficient

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        V.push_back(x);
    }
    
    void pop() {
        V.erase(V.end()-1);
    }
    
    int top() {
        return *(V.end()-1);
    }
    
    int getMin() {
        if (V.empty()) return -1;
        int temp = V[0];
        for (auto x : V)
            if (x < temp) temp = x;
        return temp;
    }
private:
    vector<int> V;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */ 



// solution 2 : maintain a min stack saving min value of current stack, and pop along with the value stack.
class MinStack2 {
private:
    stack<int> vals, mins;
public:
    /** initialize your data structure here. */
    MinStack2() {
        
    }
    
    void push(int x) {
        vals.push(x);
        if (mins.empty() || x <= mins.top()) mins.push(x);
    }
    
    void pop() {
        if (vals.top() == mins.top()) mins.pop();
        vals.pop();
    }
    
    int top() {
        return vals.top();
    }
    
    int getMin() {
        return mins.top();
    } 
};

int main()
{



    return 0;
}

