#include<iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        string ans(l1 + l2, '0');
        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                // i + j + 1 to the last digit
                int sum = (ans[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                ans[i + j + 1] = sum % 10 + '0';
                ans[i + j] += sum / 10;
            }
        }
        for (int i = 0; i < ans.size(); i++)
            // i = ans.size() - 1 is precaution for 0 * 0 where all ans digits are 0s 
            if (ans[i] != '0' || i == ans.size() - 1) return ans.substr(i);
        return "";
    }
};


int main()
{
    Solution S;
    cout<<"The answer is: "<<  S.multiply("12", "23") << endl;
    return 0;
}