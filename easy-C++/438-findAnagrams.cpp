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
#include<bitset>
#include<unordered_map>
using namespace std;

// 2018.7.26

// leetcode 438 : findAnagrams / 找到字符串中所有字母异位词

template<typename T1, typename T2>
void printMap(unordered_map<T1, T2> M) {
	for (auto x : M) {
		cout << x.first << " : " << x.second << endl;
	}
	cout << endl;
}




// solution : traverse to use hash map for every index ----------> time limit exceed
// time : O(|s|*|p|)
// space: O(|p|)
// attention : string::size_type is unsigned, overflow is need to be conisdered
// result : -------------------------> time limit exceed

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	vector<int> res;
    	if (s.length() < p.length())
			return res;
        for (int i = 0; i <= s.length()-p.length(); i ++) {
        	unordered_map<char, int> ms, mp;
        	for (int j = 0; j < p.length(); j ++) {
        		ms[s[i+j]] ++;
        		mp[p[j]] ++;
			}
			if (ms.size() != mp.size()) continue;
			bool same = true;
			for (auto x : ms) {
				if (mp[x.first] == x.second) continue;
				else {
					same = false;
					break;
				}
			}
			if (same) res.push_back(i);
		}
		return res;
    }
};



// solution 2 : use hash array
// trick : judge whether two vectors equal, just use == (as long as the data type is a built-in type)

// trick : 实时更新哈希表并判断两个是否相等 

// time : O(|s|*|p|)
// space: O(256)
// execution time: 32ms
class Solution2 {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> hash1(256), hash2(256);     // if size of vector is 26 , there will be just alright
		for (auto ch : p) hash1[ch] ++;
		int lens = s.length(), lenp = p.length();
		vector<int> ans;
		for (int i = 0; i < lens; i ++) {
			hash2[s[i]] ++;
			if (i >= lenp) hash2[s[i-lenp]] --; // update hash table in time
			if (hash1 == hash2) ans.push_back(i-lenp + 1); // just use == to judge equal
		}
		return ans;
	}
};
 


template<typename T>
void printVec(vector<T> vec) {
	for (auto x : vec) {
		cout << x << " ";
	}
	cout << endl;
}





int main()
{
	string s, p;
	Solution2 S;
	while (cin >> s >> p) {
		printVec(S.findAnagrams(s, p));
	}


	return 0;
}

