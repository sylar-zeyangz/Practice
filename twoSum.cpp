#include<unordered_map> 
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;

        for (int i = 0; ; ++i) {
            auto it = imap.find(target - nums[i]);

            if (it != imap.end()) 
                return vector<int> {i, it->second};

            imap[nums[i]] = i;
        }
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
    vector<int> input = {2, 7, 1, 15};
    vector<int> result;
    result = S.twoSum(input, 16);
    cout<<"The answer is: "<< result << endl;
    return 0;
}