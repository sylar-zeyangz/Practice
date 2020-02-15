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
};

int main() {
    Solution S;
    cout << S.mySqrt(8) << endl;
    return 0;
}