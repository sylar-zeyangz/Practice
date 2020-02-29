#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        //for (int i = 0; i < s.size(); i++) 
        //    cout << s[i];
        int count = 0;
        int i = s.size() - 1;
        for (; i >= 0 && s[i] == ' '; i--);
        for (; i >= 0 && s[i] != ' '; i--, count++);
        return count;
    }
};

int main()
{
    Solution S;
    string a = "dasjk jdoiqjo";

    cout<<"The answer is: "<<  S.lengthOfLastWord(a) << endl;
    return 0;
}