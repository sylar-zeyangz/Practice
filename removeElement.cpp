#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
            if (nums[j] != val)
                nums[i++] = nums[j];
        nums.erase(nums.begin() + i, nums.end());
        return i;
    }
};

int main()
{
    Solution S;
    vector<int> a{0,1,1,2,2,2,3,4,4,5,6,7};
    cout << "The answer is: " << S.removeElement(a, 2) << endl;
    cout << "--------\n";
    for (int i = 0; i < a.size(); i++) 
        cout << a[i];
    return 0;
}