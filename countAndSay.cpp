#include<iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; i++) {
            str = say(str);
        }
        return str;
    }
    
    string say(const string& str) {
        string ret = "";
        int len = str.size(), curr = 0;
        for (int i = 1; i <= len; i++) {
            if (i == len || str[i] != str[curr]) {
                int count = i - curr;
                // + '0' to transform int to string
                ret += '0' + count;
                ret += str[curr];
                curr = i;
            }
        }
        return ret;
    }
};

int main()
{
    Solution S;
    cout << S.countAndSay(6) << endl;
    return 0;
}