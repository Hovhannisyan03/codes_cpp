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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(!root)
        {
            return {};
        }
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> result;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty())
        {
            int size = q.size();
            std::vector<int> row(size);

            for(int i = 0; i < size; ++i)
            {
                TreeNode* current = q.front();
                q.pop();

                int index = leftToRight ? i : size - 1 - i;
                row[index] = current->val;

                if(current->left)
                {
                    q.push(current->left);
                }
                if(current->right)
                {
                    q.push(current->right);
                }
            }

            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};
