#include<iostream>
#include<climits>
#include<limits>
using namespace std;

/* class Solution {
public:
    double myPow(double x, int n) {
        bool negative = n>0 ? false : true;
        double ans = 1.0;
        double inf = numeric_limits<double>::infinity();
        if (x > 0)
            for (int i = 0; i < abs(n); i++) {
                if (INT_MAX / x <= ans) return inf;
                ans *= x;
            }
        else
            for (int i = 0; i < abs(n); i++) {
                cout << ans << ' ';
                if (INT_MIN / x <= ans) return -inf;
                ans *= x;
            }
        cout << ans;
        return negative ? 1.0/ans : ans;
    }
}; */

class Solution {
public:
    double myPow(double x, int n) {
        return n >= 0 ? myPowImp(x, n) : 1.0 / myPowImp(x, n);
    }
private:
    double myPowImp(double x, int n) {
        if (n == 0) return 1;
        return myPowImp(x * x, n / 2) * (n % 2 ? x : 1);
    }
};

int main()
{
    Solution S;
    cout<<"The answer is: "<<  S.myPow(1000, INT_MAX) << endl;
    return 0;
}