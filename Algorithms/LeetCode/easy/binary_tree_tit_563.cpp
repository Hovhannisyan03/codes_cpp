/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findTilt(TreeNode* root) 
    {
        int tilt = 0;
        helper(root,tilt);
        return tilt;
    }

    int helper(TreeNode* node, int& tilt)
    {
        if(!node)
        {
            return 0;
        }
        int left = helper(node->left,tilt);
        int right = helper(node->right,tilt);
        
        tilt += abs(left - right);
        return left + right + node->val;
    }
};
