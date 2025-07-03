#include <stack>
#include <vector>
#include <iostream>

// In order Traversal of a BST 
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        current = root;
        while (current || !s.empty()) {
            while (current) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            // track the inorder traversal
            result.push_back(current);
            current = current->right;
        }
    }
    
    int next() {
        return result[index++]->val;
    }
    
    bool hasNext() {
        return index < result.size();        
    }
private:
    std::stack<TreeNode*> s;
    TreeNode* current;
    std::vector<TreeNode*> result;

    int index = 0;
};

int main() {
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    
    BSTIterator* obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();
    int param_3 = obj->next();
    bool param_4 = obj->hasNext();
    int param_5 = obj->next();
    bool param_6 = obj->hasNext();
    int param_7 = obj->next();
    bool param_8 = obj->hasNext();
    int param_9 = obj->next();

    std::cout << param_1 << std::endl;
    std::cout << param_2 << std::endl;
    std::cout << param_3 << std::endl;
    std::cout << param_4 << std::endl;
    std::cout << param_5 << std::endl;
    std::cout << param_6 << std::endl;
    std::cout << param_7 << std::endl;
    std::cout << param_8 << std::endl;
    std::cout << param_9 << std::endl;
    delete obj;
    return 0;
}