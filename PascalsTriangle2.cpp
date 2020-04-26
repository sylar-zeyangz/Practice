#include<iostream>
#include<vector>
using namespace std;

// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

class Solution {
public:

    // DP solution
    vector<int> getRow(int rowIndex) {
        vector<int> res = vector<int>(rowIndex + 1, 1);
        
        // 0-indexed rows
        for (int row = 1; row <= rowIndex; ++ row)
            // Reverse the order so no extra space needed
            for (int i = row - 1; i > 0; -- i)
                res[i] += res[i - 1];
        
        return res;
    }
};

ostream& operator<<(ostream& os, const vector<int> &input) {
    for (auto const& i: input) {
        os << '[';
        os << i << " ";
        os << "\b]";
    }
    return os;
}

int main()
{
    Solution S;

    cout<<"The answer is: "<<  S.getRow(5) << endl;
    return 0;
}

