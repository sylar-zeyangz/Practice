#include<iostream>
#include<vector>
using namespace std;

// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows <= 0) return {};
        vector<vector<int>> ans(numRows);;
        ans[0] = {1};
        for(int r = 1; r < numRows; ++r) {
            ans[r].push_back(1);
            for (int c = 1; c < r; ++c) {
                ans[r].push_back(ans[r-1][c-1] + ans[r-1][c]);
            }
            ans[r].push_back(1);
        }
        return ans;
    }
};

ostream& operator<<(ostream& os, const vector<vector<int>> &input) {
    for (auto const& i: input) {
        os << '[';
        for (int j = 0; j<i.size(); j++)
            os << i[j] << " ";
        os << "\b]";
    }
    return os;
}

int main()
{
    Solution S;

    cout<<"The answer is: "<<  S.generate(5) << endl;
    return 0;
}

