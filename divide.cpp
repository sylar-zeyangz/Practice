#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!dividend) return 0;
        if (divisor == 1) return dividend;
        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        // bool negative = dividend < 0 ^ divisor < 0; // XOR -> ^
        int ret = 0;
        if (dividend > 0 && divisor > 0)
            for (; (dividend - divisor) >= 0; ret++)
                dividend -= divisor;
        else if (dividend < 0 && divisor < 0)
            for (; (dividend - divisor) <= 0; ret++)
                dividend -= divisor;
        else if (dividend < 0 && divisor > 0)
            for (; (dividend + divisor) <= 0; ret--)
                dividend += divisor;
        else
            for (; (dividend + divisor) >= 0; ret--)
                dividend += divisor;
        return ret;
    }
};

int main()
{
    Solution S;
    //cout << (-5 ^ 5);
    cout << "The answer is: " << S.divide(INT_MAX, INT_MAX) << endl;
    return 0;
}