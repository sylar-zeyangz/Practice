#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* buildBST(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        int m = l + (r - l)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = buildBST(nums, l, m-1);
        root->right = buildBST(nums, m+1, r);
        return root;
    }
};

int main()
{
    Solution S;
    vector<int> a{-10,-3,0,5,9};
    return 0;
}