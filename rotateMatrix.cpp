#include<algorithm> 
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        cout << n;
        // mirroring first
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            swap(matrix[i][j], matrix[j][i]);
        // reverse the row
        for (int i = 0; i < n; ++i)
            reverse(begin(matrix[i]), end(matrix[i]));
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
    vector<vector<int>> a{{1,2,3},{4,5,6},{7,8,9}};
    S.rotate(a);
    cout<<"The answer is: "<< a << endl;
    return 0;
}