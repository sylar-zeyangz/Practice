#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Assume for every set of input has one and only one solution .
        //if (nums.size() < 3) return -1;
        sort(nums.begin(),nums.end());
        int sum = 0;
        int max_distance = INT_MAX;
        for(int i = 0;i+2<nums.size();i++) {
            int spos = i+1;
            int epos = nums.size() - 1;
            while(spos<epos) {
                int s = nums[i] + nums[spos] + nums[epos];
                if(s == target) 
                    return s;
                if( abs(s - target) < max_distance ) {
                    max_distance = abs(s - target);
                    sum = s;
                }
                if(s > target)
                    epos--;
                else 
                    spos++; 
            }
        }
        return sum;   
    }
};


int main()
{
    Solution S;
    vector<int> a = {-1,2,1,-4};
    cout<<"The answer is: "<< S.threeSumClosest(a, 1) << endl;
    return 0;
}
