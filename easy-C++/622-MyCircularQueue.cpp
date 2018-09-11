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

// 2018.8.3

// leetcode 622 : MyCircularQueue / 设计一个循环队列


// solution : use array, rear point to the next position of rear, front point to front
class MyCircularQueue {
private:
    int * data;
    int size, front, rear;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data = new int[k+1];
        size = k+1;
        front = rear = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (!isFull()) {
            data[rear] = value;
            rear = (rear+1) % size;
            return true;
        }
        else return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (!isEmpty()) {
            front = (front+1) % size;
            return true;
        }
        else return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (!isEmpty()) {
            return data[front];
        }
        else return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (!isEmpty()) {
            return data[(rear-1+size) % size];
        }
        else return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == rear;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return front == (rear+1+size) % size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */ 



// solution 2 : use single linked list to implement, insert to tail, and delete from head
// result : execution error : WTF !!!


struct Node {
    int val;
    Node * next;
    Node(int value) : val(value), next(nullptr) {}    
};

class MyCircularQueue2 {
private:
    Node * pHead, * pTail;
    int capacity, size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue2(int k) {
        capacity = k;
        size = 0;
        pHead = new Node(0);
        pTail = pHead;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (!isFull()) {
            Node * tmp = new Node(value);
            pTail->next = tmp;
            pTail = pTail->next;
            size ++;
            return true;
        }
        else return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (!isEmpty()) {
            Node * tmp = pHead->next;
            pHead->next = tmp->next;
            delete tmp;
            size --;
            return true;
        }
        else return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : pHead->next->val;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : pTail->val;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == capacity;
    }
};



int main()
{



    return 0;
}

