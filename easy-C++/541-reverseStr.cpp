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
using namespace std;

// 2018.7.29

// leetcode 541 : reverseStr / ·´×ª×Ö·û´®


// solution : 
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = ceil(s.length()*0.5/k);
        for (int i = 0; i < n; i ++) {
        	for (int l = 2*i*k, r = min((2*i+1)*k-1, int(s.length()-1)); l < r; l ++, r--) {
        		swap(s[l], s[r]);
			}
		}
		return s;
    }
}; 


int main()
{



	return 0;
}

