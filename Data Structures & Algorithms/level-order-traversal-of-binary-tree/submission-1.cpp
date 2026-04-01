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
    set up a queue, add each level to uqeue, keep track of length in queue and pop that
    length in the queue
    */
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;

        if (!root) {
            return result;

        }

        q.push(root);

        while (!q.empty()) {
            int levelsize = q.size();
            vector<int> level; 

            for (int i = 0; i < levelsize; i++) {
                TreeNode* front = q.front();

                if (front-> left) {
                    q.push(front->left);

                }

                if (front -> right) {
                    q.push(front->right);

                }

                level.push_back(front->val);
                q.pop();

                



            }

            result.push_back(level);



        } 

        return result;
        
    }
};
