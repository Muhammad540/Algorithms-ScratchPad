/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root){
        return false;  
    }

    if (!root->left && !root->right){
        return (targetSum==root->val);
    }
    targetSum -= root->val;
    if (hasPathSum(root->left, targetSum)){
        return true;
    }
    if (hasPathSum(root->right, targetSum)){
        return true;
    }
    return false;
}
