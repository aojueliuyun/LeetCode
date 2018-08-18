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

// 2018.7.21

// leetocde : hammingWeigh : ������һ���޷�������������������Ʊ��ʽ������λ��Ϊ ��1�� �ĸ�����Ҳ����Ϊ���������� 


// solution : just bit operation
// time: O(logn)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
        	if (n & 1) count ++; // n % 2 == 1
        	n >>= 1;
		}
		return count;
    }
};

// solution 2 : not completely understand, consider cool
// time: O(logn)
class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n>0)
        {
            n = n&(n-1);
            ans++;
        }
        return ans;        
    }
};


int main()
{
	Solution2 S;
	uint32_t n;
	while (cin >> n) {
		cout << S.hammingWeight(n) << endl;
	}


	return 0;
}

