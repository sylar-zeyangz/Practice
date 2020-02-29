#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carr_out = false;
        for (int i = digits.size() - 1; i >= 0;) {
            if (i == 0 && digits[i] == 9)
                carr_out = true;
            if (digits[i] != 9) {
                ++digits[i];
                break;
            }
            else {
                digits[i] = 0;
                --i;
            }
        }
        if (carr_out)
            digits.insert(digits.begin(), 1);
        return digits;
    }
   
};

ostream& operator<<(ostream& os, const vector<int> &input)
{
    for (auto const& i: input) {
        os << i << " ";
    }
    return os;
}

int main()
{
    Solution S;
    vector<int> a{1,2,3};

    cout<<"The answer is: "<<  S.plusOne(a) << endl;
    return 0;
}