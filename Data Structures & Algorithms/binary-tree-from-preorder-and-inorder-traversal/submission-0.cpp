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
unordered_map<int, int> inIndex;  // maps value -> index in inorder

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int preL, int preR, int inL, int inR) {
        if (preL > preR || inL > inR)
            return nullptr;

        int rootVal = preorder[preL];
        TreeNode* root = new TreeNode(rootVal);

        int k = inIndex[rootVal];  // index of root in inorder
        int leftSize = k - inL;

        root->left = build(preorder, inorder,
                           preL + 1, preL + leftSize,
                           inL, k - 1);

        root->right = build(preorder, inorder,
                            preL + leftSize + 1, preR,
                            k + 1, inR);

        return root;
    }

    public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Precompute inorder positions for O(1) lookup
        for (int i = 0; i < inorder.size(); i++)
            inIndex[inorder[i]] = i;

        return build(preorder, inorder, 
                     0, preorder.size() - 1,
                     0, inorder.size() - 1);
    }
};
