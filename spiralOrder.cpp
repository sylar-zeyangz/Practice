#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        /*  1. go right => –-top
            2. go down => –-right
            3. go left => ++bottom
            4. go up => ++left
        */
        int l = 0;
        int t = 0;
        int r = matrix[0].size() - 1;
        int b = matrix.size() - 1;
        const int total = (r+1) * (b+1);      
        // edge to control the edges of the square
        int edge = 0;
        int x = 0;
        int y = 0;
        vector<int> ans;
        while (ans.size() < total - 1) {      
            if (edge == 0) {
                while (x < r) ans.push_back(matrix[y][x++]);
                ++t;
            } else if (edge == 1) {
                while (y < b) ans.push_back(matrix[y++][x]);
                --r;
            } else if (edge == 2) {
                while (x > l) ans.push_back(matrix[y][x--]);
                --b;
            } else if (edge == 3) {
                while (y > t) ans.push_back(matrix[y--][x]);
                ++l;
            }
            edge = (edge + 1) % 4;
        }
        // add the central element if there's one left
        if (ans.size() != total) ans.push_back(matrix[y][x]);
        return ans;
    }
};

ostream& operator<< (ostream& os, const vector<int>& v) {
    for (const int& i : v)
        cout << i << ", ";
    return os;
}

int main()
{
    Solution S;
    vector<vector<int>> a{{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};
    /*
    [[1,2,3],
     [4,5,6],
     [7,8,9],
     [10,11,12],
     [13,14,15]]
    */
    cout<<"The answer is: "<<  S.spiralOrder(a) << endl;
    return 0;
}