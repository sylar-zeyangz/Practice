#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        return {findLeftPos(nums, target), findRightPos(nums, target)};
    }
    
    int findLeftPos(vector<int> nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target)
                hi = mid;
            else
                lo = mid + 1;
        } 
        if (nums[lo] != target || lo == nums.size()) return -1;
        return lo;
    }
    
    int findRightPos(vector<int> nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target)
                hi = mid;
            else
                lo = mid + 1;
        } 
        lo--;
        if (lo < 0) return -1;
        if (nums[lo] != target) return -1;
        return lo;
    }
};

int main()
{
    Solution S;
    vector<int> a{3,3,4,4,4,5};
    vector<int> output = S.searchRange(a, 5);
    for (int i = 0; i < output.size(); i++)
        cout << output[i] << " ";
    return 0;
}