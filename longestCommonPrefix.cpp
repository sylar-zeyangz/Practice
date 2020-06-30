#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 0) return "";
        string lstring = strs[0];
        for (int i = 1; i<strs.size(); i++) {
            for (int j = 0; j < lstring.size(); j++) {
                if (lstring[j] != strs[i][j]) {
                    lstring = lstring.substr(0, j);
                    break;
                }
            }
        }
        return lstring;
    }
};
int main()
{
    Solution S;
    vector<string> s{"asdarwq", "asDSDSADs", "asd1832h"};
    cout<<"The answer is: "<< S.longestCommonPrefix(s) << endl;
    return 0;
}
