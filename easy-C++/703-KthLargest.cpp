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

// 2018.8.13

// leetcode 703 : KthLargest / 数据流中的第K大元素


// solution 1 : search and insert
class KthLargest {
private:
	vector<int> data;
	int k;
public:
    KthLargest(int k, vector<int> nums) : k(k), data(nums) {
    	sort(data.begin(), data.end());
    }
    
    int add(int val) {
        auto iter = lower_bound(data.begin(), data.end(), val); // binary search
        data.insert(iter, val);
        return data[data.size()-k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */



// solution 2 : use priority queue / heap ----------> To be continued
class KthLargest {
public:
    KthLargest(int k, vector<int> nums){
    	
    }
    int add(int val) {
    	
    }
};



int main()
{



	return 0;
}

