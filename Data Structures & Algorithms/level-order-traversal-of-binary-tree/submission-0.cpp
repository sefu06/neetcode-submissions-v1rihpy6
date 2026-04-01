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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if (root == nullptr) {
            return result;
        }

       
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> oneLevel;
            oneLevel.clear();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* parent = q.front();
                if (parent->left) {
                    q.push(parent->left);
                }

                if (parent -> right) {
                    q.push(parent->right);
                }
                q.pop();
                oneLevel.push_back(parent->val);
                

            }

            result.push_back(oneLevel);


        }

        return result;

        

        
    }
};
