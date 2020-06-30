#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            // These two are only possible when integer x is either 
            // 8463847412 (first digit greater than 7) or -9463847412 (first digit less than -8)
            if ( ret < INT_MIN/10 || ret > INT_MAX/10 || 
                 (ret == INT_MAX/10 && pop > 7) || 
                 (ret == INT_MIN/10 && pop < -8 )) return 0;
            ret = ret * 10 + pop;
        }
        return ret;
    }
};

int main()
{
    int x = 1463847412;
    Solution S;
    cout<<"The answer is: "<< S.reverse(x) << endl;
    return 0;
}
