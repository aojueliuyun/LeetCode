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

// leetcode 447 : numberOfBoomerangs / 回旋镖的数量

// all points are different from each other. 

// solution : three loop to traverse 
// time: 1508ms
// time complexity : O(n^3)
// space: O(1)
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if (points.size() < 3) return 0;
        int count = 0;
        for (int i = 0; i < points.size()-2; i ++) {
            for (int j = i+1; j < points.size()-1; j ++) {
                for (int k = j+1; k < points.size(); k ++) {
                    if (distance(points[i], points[j]) == distance(points[i],points[k])) {
                        count ++;
                        if (points[j] != points[k]) count ++;
                    }
                    if (distance(points[j], points[i]) == distance(points[j],points[k])) {
                        count ++;
                        if (points[i] != points[k]) count ++;
                    }
                    if (distance(points[k], points[i]) == distance(points[k],points[j])) {
                        count ++;
                        if (points[i] != points[j]) count ++;
                    }
                }
            }
        }
        return count;
    }
    int distance(pair<int, int> a, pair<int, int> b) {
        int dis = (a.first-b.first) * (a.first-b.first) + (a.second-b.second) * (a.second-b.second);
        return dis;
    }
}; 



// solution 2 : use hash map to save all distances in one loop, count and clear map before next loop
// strategy: exchange time with space
// time: O(n^2)
// space: O(n)
class Solution2 {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int, int> dis;
        int len = points.size(), count = 0;
        for (int i = 0; i < len; i ++) {
            for (int j = 0; j < len; j ++) 
                dis[distance(points[i], points[j])] ++;
            for (auto x : dis)
                count += x.second * (x.second - 1);
            dis.clear();
        }
        return count; 
    }
    int distance(pair<int, int> a, pair<int, int> b) {
        int dis = (a.first-b.first) * (a.first-b.first) + (a.second-b.second) * (a.second-b.second);
        return dis;
    }
};



int main()
{
    vector<pair<int, int>> points{{1,0}, {0,0}, {2,0}};
    Solution2 S;
    cout << S.numberOfBoomerangs(points) << endl;


    return 0;
}

