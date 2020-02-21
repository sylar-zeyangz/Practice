#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // binary search
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                end = mid;
            else 
                start = mid + 1;
        }
        if (target > nums[end]) 
            return end + 1;
        if (target < nums[start])
            return start;
        else
            return start + (end - start) / 2;
    }
};

int main()
{
    Solution S;
    vector<int> a{1,2,3,4};
    cout << S.searchInsert(a, 5) << endl;
    return 0;
}