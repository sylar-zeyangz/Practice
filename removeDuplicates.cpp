#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if ( nums[j] != nums[i] )
                nums[++i] = nums[j];
        }
        nums.erase(nums.begin() + i + 1, nums.end());
        return i + 1;
    }
};

int main()
{
    Solution S;
    vector<int> a{0,1,1,2};
    cout << "The answer is: " << S.removeDuplicates(a) << endl;
    cout << "--------\n";
    for (int i = 0; i < a.size(); i++) 
        cout << a[i];
    return 0;
}