struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include <queue> 

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> nodeQueue;
        vector<int> list;
        
        if (!root){
            return list;
        }

        int level = 0;
        nodeQueue.push(root);
        list.push_back(nodeQueue.back()->val);
        
        while (!nodeQueue.empty()){
            int size = nodeQueue.size();
            
            for (int i =0; i < size; i++){
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if (node->left){
                    nodeQueue.push(node->left);
                }
                if (node->right){
                    nodeQueue.push(node->right);
                } 
            }
            if (list.back() == nodeQueue.back()->val){
                return list;
            }
            list.push_back(nodeQueue.back()->val);
            level ++;
        }
        return list;
    }
};
