#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return {};
        vector<string> ans;
        string s = "";
        dfs(n, n, s, ans);
        cout<<s;
        return ans;
    }
private:
    void dfs(int l, int r, string& s, vector<string>& ans) {
        if (l == 0 && r == 0) {
          ans.push_back(s);
          return;
        }
        if (r < l) return;
        if (l > 0) {
          dfs(l - 1, r, s += "(", ans);
          s.pop_back();
        }
        if (r > 0) {
          dfs(l, r - 1, s += ")", ans);
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
    cout << "The answer is: " << S.generateParenthesis(3) << endl;
    return 0;
}