#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s == "") return true;
        if ( s[0] == '}' || s[0] == ']' || s[0] == ')' ) return false;                   
        stack<char> check;
        for (const char& i : s) {
            if ( check.empty() ) {
                check.push(i);
                continue;
            }
            if ( int(i - check.top()) == 2 || int(i- check.top()) == 1 && !check.empty() )
                check.pop();
            else 
                check.push(i);
        }
        return check.empty();
    }
};

int main()
{
    Solution S;
    string s = "[(]";
    cout << "The answer is: " << S.isValid(s) << endl;
    return 0;
}