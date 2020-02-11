#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // A look-up table
        string table[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                               {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                               {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                               {"", "M", "MM", "MMM"}
                              };
        string result = "";
        int count = 0;
        while(num > 0){
            int lastDigit = num % 10;
            result = table[count][lastDigit] + result;
            num /= 10;
            count++;
        }
        return result;
    }
};

int main()
{
    Solution S;
    cout<<"The answer is: "<< S.intToRoman(124) << endl;
    return 0;
}