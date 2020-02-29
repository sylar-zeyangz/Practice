#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i_a = a.size() - 1;
        int i_b = b.size() - 1;
        string res{};
        while (i_a >= 0 || i_b >= 0) {
            int s = (i_a >= 0 ? a[i_a--] - '0' : 0) + (i_b >= 0 ? b[i_b--] - '0' : 0) + carry;
            carry = s >> 1;
            // cout << s << " " << carry << endl;
            res += '0' + (1 & s);
        }
        // cout << res << endl;
        if (carry) res += '1';
        return {rbegin(res), rend(res)};
    }
};

int main()
{
    Solution S;
    cout<<"The answer is: "<<  S.addBinary("100", "10") << endl;
    return 0;
}