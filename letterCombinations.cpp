#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string s = "";
    vector<string> strs;
    vector<string> ret;
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return ret;
        // A look-up table
        string table[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i = 0; i < digits.size(); i++)
            strs.push_back(table[digits[i] - '0']);
        //cout << strs.size();
        back_track(0);
        return ret;
    }
    
    void back_track(int n) {
        if( s.size() == strs.size() ) {
            ret.push_back(s);
            return;
        }
        for(int i = 0; i < strs[n].size(); i++){
            s.push_back(strs[n][i]);
            back_track(n+1);
            s.pop_back();
        }
    }
};

ostream& operator<<(ostream& os, const vector<string> &input)
{
    for (auto const& i: input) {
        os << i << " ";
    }
    return os;
}

int main()
{
    Solution S;
    cout<<"The answer is: "<< S.letterCombinations("") << endl;
    return 0;
}
