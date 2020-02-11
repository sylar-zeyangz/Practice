#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, lpos = 0, rpos = height.size() - 1;
        while (lpos < rpos) {
            max_area = max( max_area, min(height[lpos], height[rpos]) * (rpos - lpos) );
            if (height[lpos] > height[rpos]) rpos--;
            else lpos++;
        }
        return max_area;
    }
};

int main()
{
    // INT_MAX = 2,147,483,648;
    // INT_MIN = -2,147,483,648;
    vector<int> x = {1,8,6,2,5,4,8,3,7};
    Solution S;
    cout<<"The answer is: "<< S.maxArea(x) << endl;
    return 0;
}
