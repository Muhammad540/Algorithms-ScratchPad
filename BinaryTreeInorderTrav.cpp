struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stack> 
#include <vector> 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        auto curr_root = root;
        vector<int> result;
        stack<TreeNode*> store_lefts;

        while (curr_root != nullptr || !store_lefts.empty()){
        
            while(curr_root!=nullptr){
                store_lefts.push(curr_root);
                curr_root = curr_root->left;
            }
            
            curr_root = store_lefts.top();
            store_lefts.pop();
            
            result.push_back(curr_root->val);
            curr_root = curr_root->right;
        }
    
        return result;
    }
}; 

// Recursive solution (easy peasy lemon squeezy)
// class Solution {
// public:
//     vector<int> result;
//     vector<int> inorderTraversal(TreeNode* root) {
//         if (!root){
//             return result;
//         }

//         inorderTraversal(root->left);
//         result.push_back(root->val);
//         inorderTraversal(root->right);
//         return result;
//     }
// };