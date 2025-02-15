/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Create a hashmap to store the index of each node in the inorder array
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }

        // Call the helper function to build the tree recursively
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0,
                               postorder.size() - 1, index);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                              int inorderStart, int inorderEnd,
                              int postorderStart, int postorderEnd,
                              unordered_map<int, int>& index) {
        // Base case: if the range is invalid, return NULL
        if (inorderStart > inorderEnd || postorderStart > postorderEnd) {
            return nullptr;
        }

        // Last element in postorder is the root
        int rootVal = postorder[postorderEnd];
        TreeNode* root = new TreeNode(rootVal);

        // Get index of root in inorder
        int inorderRootIndex = index[rootVal];

        // Calculate the number of elements in the left subtree
        int leftSubtreeSize = inorderRootIndex - inorderStart;

        // Recursively construct the left subtree
        root->left = buildTreeHelper(
            inorder, postorder, inorderStart, inorderRootIndex - 1,
            postorderStart, postorderStart + leftSubtreeSize - 1, index);

        // Recursively construct the right subtree
        root->right = buildTreeHelper(
            inorder, postorder, inorderRootIndex + 1, inorderEnd,
            postorderStart + leftSubtreeSize, postorderEnd - 1, index);

        return root;
    }
};
