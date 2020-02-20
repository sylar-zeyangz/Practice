#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (haystack == "" || haystack.size() < needle.size()) return -1;
        for (int l = 0; l < haystack.size() - needle.size() + 1; l++)
            if ( needle == haystack.substr(l, needle.size()) ) return l;
        return -1;
    }
};

int main()
{
    Solution S;
    string a = "hello";
    string b = "ll";
    cout << "The answer is: " << S.strStr(a, b) << endl;
    return 0;
}