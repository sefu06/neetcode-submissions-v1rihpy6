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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;

        TreeNode* curr = root;
        if (curr == nullptr) {
            return result;
        }


        q.push(curr);

        while (!q.empty()){

        //find right-most of each level
        int size = q.size();
        TreeNode* rightmost = nullptr;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            // keep track of the last node in the level
            rightmost = node;

            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(rightmost->val);
    }

    

        return result;
        
    }
};
