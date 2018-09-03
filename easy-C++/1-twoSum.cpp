#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

// 2018.7.14

// leetcode 1 : tow sum


// sulution 1 : brute-force
// time: O(n^2) 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++){
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {0,0};
    }
}; 

// solution 2 : use hash table make time complexity of search O(1)
// time: O(n)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	unordered_map<int, int> record;
        for (int i=0; i<nums.size(); i++) {
        	int component = target - nums[i];
            if (record.find(component) != record.end()) {
            	return {record[component], i};
			}
			record[nums[i]] = i;
        }
        return {0,0};
    }
};



int main()
{


	return 0;
}

