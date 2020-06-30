#include<vector>
#include<iostream>
// #include<typeinfo>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        // s.size() -> unsigned numRows -> int
        vector<string> rows( min( static_cast<int>(s.size()), numRows) );
        int curRow = 0;
        bool down = false;
        for (char c : s) {
            rows[curRow] += c;
            if (curRow == numRows - 1 || curRow == 0) 
                down = !down;
            curRow += down ? 1 : -1; 
        }
        
        string ret = "";
        for (string row : rows) {
            ret += row;
        }
        return ret;
    }
};

int main()
{
    Solution S;
    string s = "PAYPALISHIRING";
    cout<<"The answer is: "<< S.convert(s, 4) << endl;
    return 0;
}