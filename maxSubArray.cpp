#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return INT_MIN;
        int max = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > max)
                max = sum;
            if(sum < 0)
                sum = 0;
        }
        return max;
    }
};

int main()
{
    Solution S;
    vector<int> a{-2,1,-3,4,-1,2,1,-5,4};
    a = {-2, 1};
    cout<<"The answer is: "<<  S.maxSubArray(a) << endl;
    return 0;
}