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
/*
traverse the tree, checking if both p and q can go further down in the same branch,
otherwise return node.

*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->val < p -> val && curr->val < q->val) {
                curr = curr->right;

            } else if (curr->val > p -> val && curr->val > q->val) {
                curr = curr->left;

            } else {
                return curr;
            }

        }
        
    }
};
