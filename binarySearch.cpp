#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return -1;
    }
};

int main()
{
    Solution S;
    vector<int> a{-2, 0, 3, 4, 5, 8};
    cout<<"The answer is: "<<  S.search(a, 4) << endl;
    return 0;
}