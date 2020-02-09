#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> prev;
        int low = 0, max_length = 0;
        for(int i = 0; i < s.size(); i++) {
            if(prev.count(s[i]) > 0) 
                low = max(low, prev[s[i]] + 1);
            max_length = max(max_length, i - low + 1);
            prev[s[i]] = i;
        }
        return max_length;
    }
};

int main()
{
    Solution S;
    string s = "dvdf";
    cout << "The answer is: " << S.lengthOfLongestSubstring(s) << endl;
    return 0;
}