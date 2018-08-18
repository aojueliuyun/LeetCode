#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<array>
#include<numeric>
#include<unordered_map>
using namespace std;

// 13. Rome number to integer

// Solution 1 : simulation
// time: O(n)
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int len = s.length();
		for(int i=0; i < len; i++) {
			switch(s[i]) {
				case 'M': 
					res += 1000; 
					break;
				case 'D': 
					res += 500;
					break;
				case 'C': 
					res += 100;
					if(i+1 < len && s[i+1] == 'D') {
						res += 300; 
						i ++;
					}
					if(i+1 < len && s[i+1] == 'M') {
						res += 800; 
						i ++;
					}
					break;
				case 'L': 
					res += 50;
					break;
				case 'X': 
					res += 10;
					if(i+1 < len && s[i+1] == 'L') {
						res += 30; 
						i ++;
					}
					if(i+1 < len && s[i+1] == 'C') {
						res += 80; 
						i ++;
					}
					break;
				case 'V': 
					res += 5;
					break;
				case 'I': 
					res += 1;
					if(i+1 < len && s[i+1] == 'V') {
						res += 3; 
						i ++;
					}
					if(i+1 < len && s[i+1] == 'X') {
						res += 8; 
						i ++;
					}
					break;
			} 	
		}
		return res;
    }
};


static auto _ = []{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


// Solution 2 : C++ STL, powerful lambda,  just OTZ
class Solution2 {
public:
    int romanToInt(string s) {
    	unordered_map<char, int> config{ {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
		int last{};
		return accumulate(s.begin(), s.end(), 0, [&](int &sum, char word){return sum += last = last < config[word] ? config[word] -2*last: config[word];});
    }
};


int main()
{

	Solution2 S;
	string s;
	while(cin >> s) {
		cout << S.romanToInt(s) << endl;
	}

	return 0;
}

