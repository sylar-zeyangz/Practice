#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x !=0) ) return false;
        int revertedNum = 0;
        while (x > revertedNum) {
            revertedNum = revertedNum * 10 + x % 10;
            x = x / 10;
        }
        return (x == revertedNum || x == revertedNum / 10);
    }
};

int main()
{
    // INT_MAX = 2,147,483,648;
    // INT_MIN = -2,147,483,648;
    int x = 2147447412;
    Solution S;
    cout<<"The answer is: "<< S.isPalindrome(x) << endl;
    return 0;
}
