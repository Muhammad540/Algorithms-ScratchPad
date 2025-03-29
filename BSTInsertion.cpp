#include <iostream> 


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}   
    ~TreeNode(){
        delete left;
        delete right;
    }
};

TreeNode* insertIntoBST(TreeNode* root, int val){
    if (!root){
        // base case (if root is NULL we have reached the correct position to insert just create the node here)
        return new TreeNode(val);
    }

    if (val > root->val){
        root->right = insertIntoBST(root->right, val);
    } else if (val < root->val){
        root->left = insertIntoBST(root->left, val);
    }

    return root; // after insrtion we simply return the tree 
}

void inorderTraversal(TreeNode* root){
    if (!root){
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->val << " " << std::endl;
    inorderTraversal(root->right);
}

int main() {
    std::cout << "Test Case 1: Insert into empty tree" << std::endl;
    TreeNode* root1 = nullptr;
    root1 = insertIntoBST(root1, 5);
    std::cout << "After inserting 5: " << std::endl;
    inorderTraversal(root1);

    std::cout << "Test Case 2: Create a balanced BST" << std::endl;
    TreeNode* root2 = nullptr;
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        root2 = insertIntoBST(root2, val);
    }
    std::cout << "After inserting 5,3,7,2,4,6,8: "  << std::endl;
    inorderTraversal(root2);

    std::cout << "Test Case 3: Insert duplicate values" << std::endl;
    TreeNode* root3 = nullptr;
    int values_with_duplicates[] = {5, 3, 5, 3, 7};
    for (int val : values_with_duplicates) {
        root3 = insertIntoBST(root3, val);
    }
    std::cout << "After inserting 5,3,5,3,7: " << std::endl;
    inorderTraversal(root3);

    std::cout << "Test Case 4: Create an unbalanced BST" << std::endl;
    TreeNode* root4 = nullptr;
    for (int i = 1; i <= 5; i++) {
        root4 = insertIntoBST(root4, i);
    }
    std::cout << "After inserting 1,2,3,4,5 (right-heavy tree): " << std::endl;
    inorderTraversal(root4);

    delete root1;
    delete root2;
    delete root3;
    delete root4;

    return 0; 
}