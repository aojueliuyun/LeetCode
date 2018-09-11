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

// leetcode 690 : getImportance / 员工的重要性



// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};


// solution 1 : BFS, use queue
// execution time : 20 ms
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee *> dict;
        for (auto p : employees) {
            dict[p->id] = p;
        }
        queue<Employee *> Q;
        Q.push(dict[id]);
        int sum = 0;
        while (!Q.empty()) {
            Employee * cur = Q.front();
            Q.pop();
            sum += cur->importance;
            for (auto x : cur->subordinates) {
                Q.push(dict[x]);
            }
        }
        return sum;
    }
};


// solution 2 : just recursion, brute search
// execution time : 32 ms
class Solution2 {
public:
    int getImportance(vector<Employee*> & employees, int id) {  // better pass emplyees by reference
        int sum = 0;
        for (auto p : employees) {
            if (p->id == id) {
                sum += p->importance;
                for (auto x : p->subordinates) {
                    sum += getImportance(employees, x);
                }
            }
        }
        return sum;
    }
};



int main()
{



    return 0;
}

