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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> nodequeue;
        vector<vector<int>> lists;
        int level {0};
        if (!root){
            return lists;
        }
        nodequeue.push(root);
        while (!nodequeue.empty()){
            int size = nodequeue.size();
            vector<int> list;

            for (int i=0; i < size; i++){
                auto node = nodequeue.front();
                nodequeue.pop();
                list.push_back(node->val);
                if (node->left){
                    nodequeue.push(node->left);
                } 
                if (node->right){
                    nodequeue.push(node->right); 
                }
            }
            lists.push_back(list);
            level ++;
        }
        return lists;
    }
};
