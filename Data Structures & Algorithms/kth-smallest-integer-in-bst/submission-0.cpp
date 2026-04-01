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
/**
my thoughts:
brute force - put each node into an array and then take the k-1th slot in the array
                this would be O(nlogn) cause of merge sorting -> not ideal
dfs - do an INORDER traversal while interating until we reach k. since it is a bst, the 
        the inorder traversal is the ascending order of the tree.
*/
class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int result;
        TreeNode* curr = root;
        int i = 0;
        

        while (curr != nullptr || !st.empty()) {
        // Go as far left as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
        

        curr = st.top();
        st.pop();

        result = curr->val;
        i++;

        curr = curr->right;

        if (i == k) {
            break;

        }
        }
        

        return result;

    }
        
};
