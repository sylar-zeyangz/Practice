#include<iostream>
#include<climits>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:  
    int myAtoi(string str) {
        int positive = 1, ret = 0, i = 0;
        while (str[i] == ' ') { i++; }
        if (str[i] == '-' || str[i] == '+') {
            positive = 1 - 2 * (str[i++] == '-'); 
        }
        while (str[i] >= '0' && str[i] <= '9') {
            if (ret >  INT_MAX / 10 || (ret == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (positive == 1) return INT_MAX;
                else return INT_MIN;
            }
            ret  = 10 * ret + (str[i++] - '0');
        }
        return ret * positive;
    }
    
};

int main()
{
    // INT_MAX = 2147483648;
    // INT_MIN = -2147483648;
    string s = "    -32 wew";
    Solution S;
    cout<<"The answer is: "<< S.myAtoi(s) << endl;
    return 0;
}
