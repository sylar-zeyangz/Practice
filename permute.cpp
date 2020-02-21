#include<algorithm> 
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        // dfs for permutation n = 3 (as in choosing 3 nums from vector<int> nums)
        permutation(nums, 0, nums.size(), used, ans, curr);
        return ans;
    }
    
private:
    void permutation(vector<int>& nums, int d, int n, vector<bool>& used, vector<vector<int>>& ans, vector<int>& curr) {
        if (d == n) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            permutation(nums, d+1, n, used, ans, curr);
            curr.pop_back();
            used[i] = false;
        }
    }
};

ostream& operator<<(ostream& os, const vector<vector<int>> &input)
{
    for (auto const& i: input) {
        os << '[';
        for (int j = 0; j<i.size(); j++)
            os << i[j] << " ";
        os << ']';
    }
    return os;
}

int main()
{
    Solution S;
    vector<int> a{1,2,3};
    vector<vector<int>> ans = S.permute(a);
    cout<<"The answer is: "<< ans << endl;
    return 0;
}