#include<unordered_map> 
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> imap;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            imap[s].push_back(strs[i]);
        }
        for ( auto it = imap.begin(); it != imap.end(); it++ )
            ans.push_back(it->second);
        return ans;
    }
};

ostream& operator<<(ostream& os, const vector<vector<string>> &input)
{
    for (int i = 0; i < input.size(); i++) {
        os << '[';
        for (int j = 0; j < input[i].size(); j++)
            os << input[i][j] << " ";
        os << ']';
    }
    return os;
}

int main()
{
    Solution S;
    vector<string> a{"tea", "ate", "tan", "bus", "tae", "sub"};
    vector<vector<string>> ans = S.groupAnagrams(a);
    cout<<"The answer is: "<< ans << endl;
    return 0;
}