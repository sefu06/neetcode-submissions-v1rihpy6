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
 do an in order traversal, then traverse the list to the kth element.
 */

class Solution {
    vector<int> inorder;
public:
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root);
        return inorder[k-1];
        
    }

private: 
    void inOrder(TreeNode* node) {
        if (!node) {
            return;
        }

        inOrder(node->left);

        inorder.push_back(node->val);

        inOrder(node->right);

    }
};
