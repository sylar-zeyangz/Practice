#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the first desending num
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) 
            i--;
        // if find
        if (i >= 0) {
          int j = nums.size() - 1;
          // find the smallest num that is larger than nums[i]
          while (j >= 0 && nums[j] <= nums[i]) 
              j--;
          swap(nums[i], nums[j]);
        }
        // if not find
        // desending array -> reverse it for minimum
        reverse(begin(nums) + i + 1, end(nums));
    }   
};

int main()
{
    Solution S;
    vector<int> a{2,3,1};
    S.nextPermutation(a);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    return 0;
}