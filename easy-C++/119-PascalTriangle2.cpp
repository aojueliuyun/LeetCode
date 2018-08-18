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

// 2018.7.16

// leetcode 119 : Pascal Trangle ------> 输出其中第k行，时间复杂度要求 O(k) 

// solution : C(n,m) = C(n-1, m-1) + C(n-1, m)
// time: O(k*k)
// space: O(k)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec1(34), vec2(34);
        for (int i = 0; i <= rowIndex; i ++) {
        	if (i % 2 == 0) {
        		vec1[0] = 1;
        		for (int j = 1; j < i; j ++)
        			vec1[j] = vec2[j-1] + vec2[j];
        		vec1[i] = 1;
			}
			else {
				vec2[0] = 1;
				for (int j = 1; j < i; j ++)
					vec2[j] = vec1[j-1] + vec1[j];
				vec2[i] = 1;
			}
		}
		vec1.resize(rowIndex+1);
		vec2.resize(rowIndex+1);
		return rowIndex % 2 == 0 ? vec1 : vec2;
    }
};


// solution 2 : just use one vector
// time: O(k^2)
// space: O(k)
class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        for (int i = 0; i < rowIndex; i ++) {
        	int temp = res[i];
        	for (int j = 1; j <= i; j ++) {
        		int tempp = res[j];
        		res[j] += temp;
        		temp = tempp;
			}
			res.push_back(1);
		}
		return res;
    }
};








void printVec(vector<int> V) {
	for (int i = 0; i < V.size(); i ++)
		cout << V[i] << ' ';
	cout << endl;
}



int main()
{

	Solution2 S;
	int n;
	while (cin >> n) {
		printVec(S.getRow(n));
	}

	return 0;
}

