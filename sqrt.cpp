#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        while (l <= r) {
            int m = l + (r - l)/2;
            if (m > x / m)
                r = m - 1;
            else
                l = m + 1;
        }
        return r;
    }
    
    int newtonSqrt(int x) {
        double a = x;
        const double delta = 0.2;
        while ( (a * a - x) > 0.2 ) {
            a = (a + x / a) / 2.0;
        }
        return a;
    }
};

int main() {
    Solution S;
    cout << S.newtonSqrt(5) << endl;
    return 0;
}