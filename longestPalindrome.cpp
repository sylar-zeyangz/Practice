#include<unordered_map> 
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:    
    // Better interpretation
    string longestPalindrome(string s) { 
        const int n = s.length();
        auto getLen = [&](int l, int r)
        {
            while (l >= 0 && r < n && s[l] == s[r]) 
            {
                --l;
                ++r;
            }
            return r - l - 1;
        };
        int max_len = 0, start = 0;
        for (int i = 0; i < n; ++i) 
        {
            int cur_len = max(getLen(i, i), getLen(i, i + 1));
            if (cur_len > max_len)
            {
                max_len = cur_len;
                start = i - (cur_len - 1) / 2;
            }
        }
        return s.substr(start, max_len);
    }
    
    string longestPalindrome_archive(string s) {
        if (s.size() <= 1) 
            return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();) {
            if (s.size() - i <= max_len / 2) 
                break;
            int j = i, k = i;
            while (k < s.size()-1 && s[k+1] == s[k]) 
                ++k; // Skip duplicate characters.
            i = k+1;
            while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { 
                ++k; 
                --j;
            } // Expand.
            int new_len = k - j + 1;
            if (new_len > max_len) { 
                min_start = j; 
                max_len = new_len;
            }
        }
        return s.substr(min_start, max_len);
    }
};

int main()
{
    Solution S;
    string s = "asdsdswiwoe";
    cout<<"The answer is: "<< S.longestPalindrome(s) << endl;
    return 0;
}
