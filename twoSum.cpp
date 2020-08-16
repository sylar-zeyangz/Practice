#include<unordered_map> 
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;

        for (int i = 0; i < nums.size() ; ++i) {
            auto it = imap.find(target - nums[i]);

            if (it != imap.end()) 
                return {it->second, i};

            imap[nums[i]] = i;
        }
        return {};
    }
};

ostream& operator<<(ostream& os, const vector<int> &input)
{
    for (auto const& i: input) {
        os << i << " ";
    }
    return os;
}

int main()
{
    Solution S;
    vector<int> input = {2, 3, 5, 7};
    vector<int> result;
    result = S.twoSum(input, 10);
    cout<<"The answer is: "<< result << endl;
    return 0;
}