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
    /*
    traverse by level and take the right most node of each level
    */
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;

        if (!root) {
            return result;

        } 

        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            
            result.push_back(q.front()->val);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* front = q.front();

                if (front->right) {
                    q.push(front->right);

                }

                if (front->left) {
                    q.push(front->left);

                }

                q.pop();

            }

        }

        return result;
        
        
    }
};
