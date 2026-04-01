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
    int goodNodes(TreeNode* root) {
        //dfs : use stack
        //use recursion
        if (!root) return 0;

        int result = 0;

        // stack stores: (node pointer, max value seen so far on that path)
        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});

        while (!st.empty()) {
            auto [node, maxSoFar] = st.top();
            st.pop();

            // Check if this node is "good"
            if (node->val >= maxSoFar) {
                result++;
            }

            // Update max for children
            int newMax = max(maxSoFar, node->val);

            if (node->left) {
                st.push({node->left, newMax});
            }
            if (node->right) {
                st.push({node->right, newMax});
            }
        }

        return result;

    }
};
