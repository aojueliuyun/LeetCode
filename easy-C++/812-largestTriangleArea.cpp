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

// 2018.8.18

// leetcode 812 : largestTriangleArea


// the triangle area equation : A (x1, y1) B(x2, y2) C(x3, y3)
//                area = (1/2)*|(x1y2+x2y3+x3y1-x1y3-x2y1-x3y2)|   --->  need add || / abs()


// solution 1 : brute-force 
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0;
        int n = points.size();
        for (int i = 0; i < n; i ++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i+1; j < n; j ++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                for (int k = j+1; k < n; k ++) {
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    area = max(area, 0.5 * abs(x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2));
                }
            }
        }
        return area;
    }
};



int main()
{



    return 0;
}

