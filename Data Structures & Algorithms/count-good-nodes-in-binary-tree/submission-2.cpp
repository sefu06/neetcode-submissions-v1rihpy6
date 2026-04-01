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
    keep track of a max as you traverse the tree? dfs for sure...

    */
public:
int result = 0;
    int goodNodes(TreeNode* root) {
        
        dfs(root, -101);
        return result;


        
    }

private:
    void dfs(TreeNode* root, int max) {
        if (!root) {
            return;
        }

        if (root->val >= max) {
            result++;
            dfs(root->left, root->val);
            dfs(root->right, root->val);


        } else {
            dfs(root->left, max);
            dfs(root->right, max);
        }

       
    }
};
