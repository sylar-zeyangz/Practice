#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        // space: n
        // time: nlogn
        vector<int> ret(num + 1, 0);
        for (int i = 0; i <= num; ++i) {
            int n = i; 
            int count = 0;
            while (n) {
                count += n & 1;
                n = n>>1;
            }
            ret[i] = count;
        }
        return ret;
    }
    
    // Brian Kernighan Algorithm
    vector<int> countBits_BK(int num) {
        // space: n
        // time: nlogn
        vector<int> ret(num + 1, 0);
        for (int i = 0; i <= num; ++i) {
            int n = i; 
            int count = 0;
            while (n) {
                n = n & (n - 1);
                ++count;
            }
            ret[i] = count;
        }
        return ret;
    }
    
    // Look-up table (shift 4-bit at a time)
    vector<int> countBits_LT(int num) {
        // space: 2^k (in a k-bit system)
        // time: nlogn/k (in a k-bit system)
        
                    // 0, 1, 2, 3, 4, 5, 6, 7, 
        int table[] = {0, 1, 1, 2, 1, 2, 2, 3,
                    // 8, 9, 10, 11, 12, 13, 14, 15
                       1, 2,  2,  3,  2,  3,  3,  4};
        vector<int> ret(num + 1, 0);
        for (int i = 0; i <= num; ++i) {
            int count = 0;
            for (int n = i; n != 0 ; n >>= 4)
                count += table[n & 15]; // [n & 0xF]
            ret[i] = count;
        }
        return ret;
    }
};

ostream& operator<<(ostream& os, const vector<int> input)
{
    os << '[';
    for (auto const& i: input) {
        os << i << " ";
    }
    os << "\b]";
    return os;
}


int main()
{
    Solution S;
    
    cout << "The answer is: " << S.countBits(5) << endl;
    cout << "The answer (BK) is: " << S.countBits_BK(5) << endl;
    cout << "The answer (LT) is: " << S.countBits_LT(5) << endl;
    return 0;
}

