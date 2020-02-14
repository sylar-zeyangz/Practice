#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        sort(nums.begin(),nums.end());
        set<vector<int>> res;
        for(int i = 0;i<nums.size();i++) {
            int spos = i+1;
            int epos = nums.size() - 1;
            while(spos<epos) {
                int sum = nums[i] + nums[spos] + nums[epos];
                if(sum<0) {
                    spos++;
                } else if(sum>0) {
                    epos--;
                } else {
                    vector<int> cur({nums[i],nums[spos++],nums[epos--]});
                    res.insert(cur);     
                }
            }
        }
        vector<vector<int>> ans(res.begin(),res.end());
        return ans;   
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
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    cout<<"The answer is: "<< S.threeSum(a) << endl;
    return 0;
}
