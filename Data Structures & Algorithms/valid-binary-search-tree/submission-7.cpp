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
    we need to do some sort of dfs, go down the tree and check if each node's
    children are in the right place
    */
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, -1001, 1001);
    }

private:
    bool valid(TreeNode* node, int min, int max) {
        if (!node) {
            return true;

        }

        if (node->val >= max || node->val <= min) {
            return false;
            
        } else {
            return valid(node->left, min, node->val) && valid(node->right, node->val, max);
        }

    }

    
};
