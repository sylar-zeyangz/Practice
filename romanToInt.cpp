#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> table = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                            {'C', 100}, {'D', 500}, {'M', 1000} };
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (table[s[i]] < table[s[i+1]])
                sum -= table[s[i]];
            else
                sum += table[s[i]];
        }
        return sum;
    }
};

int main()
{
    Solution S;
    cout<<"The answer is: "<< S.romanToInt("MCMXCIV") << endl;
    return 0;
}
