#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Greedy -> O(n)
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return true;
        const int n = nums.size();
        int energy = nums[0];
        for (int i = 0; i < n; i++) {
            if (i > energy) break;
            energy = max(energy, i + nums[i]);
        }
        return energy >= n-1;
    }
    
    //
};

int main()
{
    Solution S;
    vector<int> a{3,0,1,0,4};

    cout<<"The answer is: "<<  S.canJump(a) << endl;
    return 0;
}