#include <iostream>

struct TreeNode {
    // struct defining a single node in the BST
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root){
        return nullptr;
    }
    
    if (val > root->val){
        return searchBST(root->right, val);
    } else if (val < root->val){
        return searchBST(root->left, val);
    } else {
        return root;
    }
}

// a recursive print method to print the 
// BST tree vals left to right 
void printTree(TreeNode* node){
    if (!node){
        return;
    }
    printTree(node->left);
    std::cout << node->val << " ";
    printTree(node->right);
}

void deleteTree(TreeNode* node){
    if (!node){
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main(void) {
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);

    std::cout << "Test Case 1:" << std::endl;
    std::cout << "Original tree (in-order): ";
    printTree(root1);
    std::cout << std::endl;

    int searchVal1 = 2;
    TreeNode* result1 = searchBST(root1, searchVal1);
    std::cout << "Searching for " << searchVal1 << ": ";
    if (result1) {
        std::cout << "Found! Subtree rooted at " << searchVal1 << " (in-order): ";
        printTree(result1);
    } else {
        std::cout << "Not found!";
    }
    std::cout << std::endl;

    int searchVal2 = 5;
    TreeNode* result2 = searchBST(root1, searchVal2);
    std::cout << "Searching for " << searchVal2 << ": ";
    if (result2) {
        std::cout << "Found! Subtree rooted at " << searchVal2 << " (in-order): ";
        printTree(result2);
    } else {
        std::cout << "Not found!";
    }
    std::cout << std::endl;

    TreeNode* root2 = new TreeNode(1);
    std::cout << "\nTest Case 2 (Single node tree):" << std::endl;
    std::cout << "Original tree: ";
    printTree(root2);
    std::cout << std::endl;

    int searchVal3 = 1;
    TreeNode* result3 = searchBST(root2, searchVal3);
    std::cout << "Searching for " << searchVal3 << ": ";
    if (result3) {
        std::cout << "Found! Value: " << result3->val;
    } else {
        std::cout << "Not found!";
    }
    std::cout << std::endl;

    TreeNode* root3 = nullptr;
    std::cout << "\nTest Case 3 (Empty tree):" << std::endl;
    int searchVal4 = 1;
    TreeNode* result4 = searchBST(root3, searchVal4);
    std::cout << "Searching for " << searchVal4 << " in empty tree: ";
    if (result4) {
        std::cout << "Found!";
    } else {
        std::cout << "Not found!";
    }
    std::cout << std::endl;

    deleteTree(root1);
    deleteTree(root2);

    return 0;
}