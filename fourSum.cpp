#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {  
        if (nums.size() < 4) return {};
        sort(nums.begin(),nums.end());
        unordered_map<int, int> imap;
        //vector<vector<int>> res; 
        // use std::set because set does not allow duplicate
        set<vector<int>> res;
        int i = 0;
        for (i = 0; i < nums.size(); i++) 
            imap[nums[i]] = i;
        for (i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                for (int k = j + 1; k < nums.size(); k++) {
                    int residual = target - nums[i] - nums[j] - nums[k];
                    // Certainly not going to find 
                    // if the residual is smaller than the smallest remaining element nums[k]
                    if (residual < nums[k]) break;
                    auto it = imap.find(residual);
                    // if not found or the found element is already been previously used.. then keep looking
                    if (it == imap.end() || it->second <= k) continue;
                    res.insert({nums[i], nums[j], nums[k], residual});
                }
        return  {res.begin(), res.end()};   
    }
};

ostream& operator<<(ostream& os, const vector<vector<int>> input)
{
    for (auto const& i: input) {
        os << '[';
        for (int j = 0; j < i.size(); j++)
            os << i[j] << " ";
        os << ']';
    }
    return os;
}

int main()
{
    Solution S;
    vector<int> a = {1, 0, -1, 0, -2, 2};
    cout<<"The answer is: "<< S.fourSum(a, 0) << endl;
    return 0;
}
