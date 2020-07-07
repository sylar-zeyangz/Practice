#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    /* Time limit exceeds
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
    } */
    
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        else if (divisor == 1)
            return dividend;
        else if (divisor == -1 && dividend == INT_MIN)
            return INT_MAX;
        else if (divisor == -1)
            return -dividend;
        
        bool negative = dividend < 0 ^ divisor < 0;
        
        unsigned int divd = dividend < 0 ? -(unsigned int)dividend : dividend;
        unsigned int divs = divisor < 0 ? -(unsigned int)divisor : divisor;
        
        int count = 0;

        while(divd >= divs)
        {
            ++count;
            divd -= divs;
        }

        return negative ? -count : count;
    }
};

int main()
{
    Solution S;
    //cout << (-5 ^ 5);
    cout << "The answer is: " << S.divide(INT_MAX, 3) << endl;
    return 0;
}