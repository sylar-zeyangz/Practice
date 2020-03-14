#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> imap;
        for (int i = 0; i < nums.size(); ++i) {
            // cout << nums[i] << " ";
            imap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size() + 1; ++i) {
            if (imap.find(i) == imap.end())
                return i;
        }
        return 0;
    }
    
    // 
    int missingNumber_bitOp(vector<int>& nums) {
        int missNum = nums.size();
        for (int i = 0; i < nums.size(); ++i) 
            missNum ^= nums[i]^i;
        return missNum;
    }
};

ostream& operator<<(ostream& os, const vector<vector<int>> input)
{
    for (auto const& i: input) {
        os << '[';
        for (int j = 0; j < i.size(); j++)
            os << i[j] << " ";
        os << ']';
    }
    return os;
}

int main()
{
    Solution S;
    vector<int> a = {5, 3, 2, 0, 1};
    cout<<"The answer is: "<< S.missingNumber(a) << endl;
    cout<<"The answer is: "<< S.missingNumber_bitOp(a) << endl;
    return 0;
}

