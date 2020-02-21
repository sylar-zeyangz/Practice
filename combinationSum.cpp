#include<algorithm> 
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        findTarget(candidates, target, 0, curr, ans); // dfs
        return ans;
    }
    void findTarget(vector<int>& candidates, int target, int s, vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        // starting from sth num, since the combination does not need duplicate combinations
        // (not permutation)
        for (int i = s; i < candidates.size(); i++) {
            // sorted array, break if the target is smaller than current candidate
            if (candidates[i] > target) break;
            curr.push_back(candidates[i]);
            // i instead of i+1, because duplicate elements are allow.
            findTarget(candidates, target - candidates[i], i, curr, ans);
            curr.pop_back();
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
    vector<int> input{2, 3, 6, 7};
    vector<vector<int>> ans = S.combinationSum(input, 7);
    cout<<"The answer is: "<< ans << endl;
    return 0;
}