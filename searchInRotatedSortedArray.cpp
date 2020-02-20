#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int peak = findPeak(nums);
        int ind = binarySearch(0, peak, nums, target);
        if (ind != -1)
            return ind;
        else
            return binarySearch(peak + 1, nums.size() - 1, nums, target);
    }
    int findPeak(vector<int> nums) { 
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid+1])
                return mid;
            if (nums[mid] < nums[r])
                r = mid;
            else 
                l = mid + 1;
        }
        return -1;
    }
    int binarySearch(int l, int r, vector<int> nums, int target) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};

int main()
{
    Solution S;
    vector<int> a{4,5,6,7,0,1,2};
    cout << S.search(a, 6) << endl;
    return 0;
}